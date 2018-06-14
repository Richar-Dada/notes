### 背景
今天面试遇到一个问题： Vue父子组件生命周期执行顺序是怎么样的？  
当时做了一顿分析后，面试官表示不太同意，事后我甚感疑惑，决定做一次整理

### 案例
现在通过一个案例来分析这个问题，分别有组件Parent/Children/SubChildren/InnerChildren
Parent组件代码：
```
<template>
  <div>
    <p>Parent</p>
    <children></children>
    <sub-children></sub-children>
  </div>
</template>


<script>
import Children from './Children'
import SubChildren from './SubChildren'

export default {
  components: {
    Children,
    SubChildren
  },
  created () {
    console.log('parent created')
  },
  mounted () {
    console.log('parent mounted')
  }
}
</script>
```
Children组件代码

```
<template>
  <div>
    <p>children</p>
    <inner-children></inner-children>
  </div>
</template>

<script>
import InnerChildren from './InnerChildren'
export default {
  components: {
    InnerChildren
  },
  created () {
    console.log('child created')
  },
  mounted () {
    console.log('child mounted')
  }
}
</script>
```
SubChildren组件
```
<template>
  <p>sub-children</p>
</template>

<script>
export default {
  created () {
    console.log('sub child created')
  },
  mounted () {
    console.log('sub child mounted')
  }
}
</script>
```

InnerChildren
```
<template>
  <p>inner-children</p>
</template>

<script>
export default {
  created () {
    console.log('inner child created')
  },
  mounted () {
    console.log('inner child mounted')
  }
}
</script>
```
输出结果
```
parent created
child created
inner child created
sub child created
inner child mounted
child mounted
sub child mounted
parent mounted
```
> 从打印结果可以看出，所有组件的created先执行，执行完后再执行mounted
> 再看created执行顺序，Parent组件执行完后，会执行第一个子组件Children，然后如果子组件
> Children有子组件会先执行里面的子组件InnerChildren，以此类推，执行完所有内部子组件后
> 才会执行Parent的第二个组件SubChildren

