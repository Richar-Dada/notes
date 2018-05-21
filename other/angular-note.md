Angular双向数据绑定实现三大关键,$watch/$apply/$digest
## $watch
watch的作用是监听,监听值的改变,更新相应的页面.
```
function watch(exp, fn){}
```
从watch的定义看到,exp的作用是获取监听值,每次获取完之后,watch记录下来,下一次获取值后,与记录下来的值做对比,如果不一样马上触发回调函数更新DOM

## $digest 脏检测
$digest的过程是这样的.Angular会用一个数组装watch,脏检测是遍历所有的watch,问他们是否值改变了,跑一圈后,有watch的值改变,脏检测会再走一遍,直到没有watch
说自己的值改变.

## $apply
apply有什么用呢?其实它是用来触发$digest的.通常我们点击按钮改变一个值,ng-click会马上调用apply,脏检测开始运行,对应的watch获取新的值,发现到不一样后,
调用回调函数更新DOM,更新完成.一轮检测结束后,下一轮检测开始,再次询问此watch,获取的新值和上一次一样,脏检测结束
