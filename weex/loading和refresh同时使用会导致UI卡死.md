### loading和refresh同时使用导致UI卡死
在list列表中,经常会有上来刷新和下拉刷新的功能,或者同时存在的情况.在Weex中,`<loading>`和`<refresh>`组件分别实现这两个功能.但在测试中发现了一个BUG  
![](./images/loading&refresh.png)  
在loading加载了时候,快速拖动列表触发refresh,页面就会卡死,不会恢复到原来的位置

### 解决办法
1. 只单独使用`<loading>`或`<refresh>`
2. 非要两个同时存在,可使用互斥法;通过`v-if="!showLoading"`和`v-if="!refreshing"`使loading的时候隐藏<refresh>,在refresh的时候隐藏<loading>,这样可以避免他们同时触发
```
<list class="timeline-body" loadmoreoffset="50" v-if="showFlightList && !showILoading" :style="{'height': contentHeight}" ref="timelineBody">
    <cell class="previous-step-box" v-if="stepList && stepNum > 1 && stepList[stepNum - 2].selectedItem">
        <div class="previous-step">
        <text class="previous-step-text previour-step-blue-text">{{ $t('departure') }}</text>
        <text class="previous-step-text">{{ stepList[stepNum - 2].selectedItem.departTime | dateToMMDDAndWeek('ZH') }}</text>
        <text class="previous-step-text">{{ stepList[stepNum - 2].selectedItem.departTime.split(' ')[1] + '-' + stepList[stepNum - 2].selectedItem.arriveTime.split(' ')[1] }}</text>
        </div>
    </cell>
    <refresh class="refresh" v-if="!showLoading" @refresh="onrefresh" :display="refreshing ? 'show' : 'hide'" style="just-content:center;align-item:center;">
        <i-gif src="/images/listLoading.gif" width="32px" height="32px"></i-gif>
    </refresh>
    <cell class="flight-box" v-for="(flight, key) in flightLists" @click="selectFlight(flight, key)" :key="flight.id">
        <flight-timeline-cell :flight-data="flight" :tripType="query.tripType" :isDomesticCabinType="query.isDomesticCabinType">
        </flight-timeline-cell>
        <div class="flight-box-modal" v-if="hasSelectedFuk == flight.fuk"></div>
    </cell>
    <!-- 底部提示占位置用的 -->
    <cell class="arrive-bottom-tips" v-if="resultsCount && query.pageSize >= resultsCount">
        <div class="line-box"></div>
        <text class="text-tips">{{ $t('arrive_bottom_tips') }}</text>
        <div class="line-box"></div>
    </cell>
    <loading class="loading" v-if="!refreshing" @loading="onloading" :display="showLoading ? 'show' : 'hide'">
    </loading>

    <!-- ios让底部保持距离 -->
    <cell style="height:120px;"></cell>
</list>
```
