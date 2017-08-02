### 事件DOMContentLoaded和load的区别

网页加载的过程
1. 当用户输入网页URL的时候，WebKit调用其他资源加载器加载该URL对应的网页
2. 加载器依赖网络模块建立连接，发送请求并接受答复
3. WebKit接受到各种网页或资源的数据，其中某些资源可能是同步或异步获取的
4. 网页被交给HTML解释器转呗成一系列的词语
5. 解释器根据词语构建节点，形成DOM树
6. 如果节点是Javascript代码的话，调用JavaScript引擎解释并执行
7. Javascript代码可能修改DOM树的结构
8. 如果节点需要依赖其他资源，例如图片、CSS、视频等，调用资源加载器来加载它们，但是它们是异步的，不会妨碍当前DOM树的继续创建；如果是JavaScript资源URL，则需要停止当前DOM树的创建，直到JavaScript的资源加载并被JavaScript引擎执行后才继续DOM树的创建

> DOMContentLoaded事件发生在DOM树构建完之后  
> load事件发生在DOM树构建完网页所依赖的资源都加载完之后