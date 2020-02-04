## PureComponent是否等于一劳永逸
- PureComponent是React15.3版本新增的类，它取代了其前身PureRenderMixin,是优化React应用程序性能的重要方法之一
- 好奇的萌新可能会问：它真的能优化？如何优化呢？

## 验证PureComponent
```js
import React, { Component } from 'react'

class Foo extends Component{
    render() {
        console.log('Foo render')
        return null
    }
}

class Pure extends Component{
    constructor() {
        super()
        this.state = {
            count: 0
        }
    }

    render() {
        console.log('Pure render')
        
        const { count } = this.state
        return (
            <div>
                <p>{count}</p>
                <button onClick={() => this.setState({count: count+1})}>Add</button>
                <Foo name="foo"></Foo>
            </div>
        )
    }
}

export default Pure
```
- 上面的代码使用的是Component，当点击Add按钮后，控制台输出 <code>Pure render</code> <code>Foo render</code>,这证明state值改变触发render函数；
- 看看Foo组件，它state/props没有任何改变，Pure组件重新渲染也会触发Foo组件重新渲染，这不太合理；
- 把Foo换成PureComponent看看有什么效果

```js
import React, { Component, PureComponent } from 'react'

class Foo extends PureComponent{
    render() {
        console.log('Foo render')
        return null
    }
}

class Pure extends Component{
    constructor() {
        super()
        this.state = {
            count: 0
        }
    }

    render() {
        console.log('Pure render')

        const { count } = this.state
        return (
            <div>
                <p>{count}</p>
                <button onClick={() => this.setState({count: count+1})}>Add</button>
                <Foo name="foo"></Foo>
            </div>
        )
    }
}

export default Pure
```

- 把Foo组件替换成PureComponent后，控制台只输出<code>Pure render</code>,Foo不再渲染实现性能优化

## PureComponent原理
查看资料和React源码，PureComponent继承Component组件，它比Component多了一个操作，对state和props进行前后比较，如果前后没有发生改变不需要重新渲染

```js
if (this._compositeType === CompositeTypes.PureClass) {
  shouldUpdate = !shallowEqual(prevProps, nextProps) || ! shallowEqual(inst.state, nextState);
}
```

- 见名知意prevProps与nextProps、inst.state与nextState进行浅比较，比较的结果作为这个Component是否渲染的依据，这跟上面的验证表现一致

```js
import React, { Component, PureComponent } from 'react'

class Foo extends PureComponent{
    render() {
        console.log('Foo render')
        return null
    }
}

class Pure extends Component{
    constructor() {
        super()
        this.state = {
            obj: {
                name: 'jack',
                age: 22,
                jobInfo: {
                    company: 'alibaba'
                }
            }
        }
    }

    changeObj1 = () => {
        const { obj } = this.state
        obj.age += 1
        this.setState({
            obj: Object.assign({}, obj)
        })
    }

    changeObj2 = () => {
        const { obj } = this.state
        obj.age += 1
        this.setState({
            obj
        })
    }

    render() {
        const { obj } = this.state
        console.log('obj', obj)

        return (
            <div>
                <p>Pure</p>
                <button onClick={this.changeObj1}>Change Obj 1</button>
                <button onClick={this.changeObj2}>Change Obj 2</button>
                <Foo obj={obj}></Foo>
            </div>
        )
    }
}

export default Pure
```

- 上面这例子，点击 Change Obj 1才会输出<code>Foo render</code>, 证明复杂数据类型比较的只是地址值，并不是数据值，毫无疑问，它只是浅比较
- 后面看到这样的代码<code>this.setState(obj:{...obj})</code><code>this.setState({arr:[...arr]})</code>，大家应该明白其中缘由了吧
- 经过上面的学习，PureComponent并没有想象中的那么复杂，Component组件也可以实现这样的效果

```js
import React, { Component, PureComponent } from 'react'

class Foo extends Component{
    shouldComponentUpdate(nextProps, nextState) {
        if (nextProps.obj != this.props.obj) {
            return true
        }
        return false
    }

    render() {
        console.log('Foo render')
        return null
    }
}

class Pure extends Component{
    constructor() {
        super()
        this.state = {
            obj: {
                name: 'jack',
                age: 22,
                jobInfo: {
                    company: 'alibaba'
                }
            }
        }
    }

    changeObj1 = () => {
        const { obj } = this.state
        obj.age += 1
        this.setState({
            obj: Object.assign({}, obj)
        })
    }

    changeObj2 = () => {
        const { obj } = this.state
        obj.age += 1
        this.setState({
            obj
        })
    }

    render() {
        const { obj } = this.state
        console.log('obj', obj)

        return (
            <div>
                <p>Pure</p>
                <button onClick={this.changeObj1}>Change Obj 1</button>
                <button onClick={this.changeObj2}>Change Obj 2</button>
                <Foo obj={obj}></Foo>
            </div>
        )
    }
}

export default Pure
```

- Foo组件只有props，在shouldComponentUpdate生命周期对props的obj进行比较，效果和前面一模一样
- Component组件也可以实现PureComponent组件功能，但需额外写一些代码，PureComponent把这些隐藏在内部，让开发人员舒服地使用，日常开发中推荐大家使用PureComponent组件；但PureComponent并非银弹，看看下面的情况

```js
import React, { Component, PureComponent } from 'react'

class Foo extends PureComponent{
    render() {
        console.log('Foo render')
        return null
    }
}

class Pure extends Component{
    constructor() {
        super()
        this.state = {
            arr: []
        }
    }

    fetch = () => {
        let result = []
        for (let i = 0; i < 100; i++) {
            result.push(i)
        }
        this.setState({
            arr: result
        })
    }


    render() {
        const { arr } = this.state

        return (
            <div>
                <p>Pure</p>
                <button onClick={this.fetch}>fetch</button>
                <Foo arr={arr}></Foo>
            </div>
        )
    }
}

export default Pure
```
- 每次获取数据，fetch得到的数据都是一样的，但是因为它是一个新的数组，它每次都需要重新渲染；如果数据量巨大，性能问题非常严重。
- JS操作永远比DOM操作好，DOM大量频繁操作往往会造成性能问题；遇到这种情况，可以在Foo组件的shouldComponentUpdate对arr的值进行比较，实现性能优化

```js
import React, { Component, PureComponent } from 'react'

class Foo extends Component{

    shouldComponentUpdate(nextProps, nextState) {
        if (nextProps.arr.length != this.props.arr.length) {
            return true
        }

        let result = false
        for (let i = 0, len = nextProps.arr.length; i < len; i++) {
            if (nextProps.arr[i] != this.props.arr[i]) {
                result = true
                break
            }
        }
        return result
    }

    render() {
        console.log('Foo render')
        return null
    }
}

class Pure extends Component{
    constructor() {
        super()
        this.state = {
            arr: []
        }
    }

    fetch = () => {
        let result = []
        for (let i = 0; i < 100; i++) {
            result.push(i)
        }
        this.setState({
            arr: result
        })
    }


    render() {
        const { arr } = this.state

        return (
            <div>
                <p>Pure</p>
                <button onClick={this.fetch}>fetch</button>
                <Foo arr={arr}></Foo>
            </div>
        )
    }
}

export default Pure
```

- React 在Component中提供了shouldComponentUpdate生命周期，把渲染的权利交给了开发人员，开发人员根据实际情况实现最大限度的优化。
- PureComponent 使用方便兼顾性能，极其适合萌新使用，两者配合使用，极其舒服，真的是优秀的设计