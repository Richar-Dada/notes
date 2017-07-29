### Date 的小坑
Date 是一个经常使用的类，创建一个新的时间 `new Date()`, 创建一个特定的时间`new Date('2017-7-28')`，
简单易用，但是它在IOS就会出问题。

IOS只接受这种创建时间的写法`var date =new Date("2016/05/31 08:00");`

为了兼容安卓和苹果，需要对时间进行一次格式化
```
function GetDateDiff(startDiffTime, endDiffTime) {  
            //将xxxx-xx-xx的时间格式，转换为 xxxx/xx/xx的格式   
            startTime = startDiffTime.replace(/\-/g, "/");  
            endTime = endDiffTime.replace(/\-/g, "/");  
}; 
```

平台兼容小坑，记录一波
