# DOM(文档对象模型)

HTML文档被当作一颗DOM树来看待

```javascript
var domObj = document.getElementById("id");
```

## DOM和BOM的区别和联系

> DOM和BOM的区别和联系?
> BOM的顶级对象是:window
> DOM的顶级对象是:document
> 实际上B0M是包括DOM的!

```html
<script type ="text/javascript">
window.onload =function(){//
    var btnElt = window.document.getElementById("bth");
    var btnElt =document.getElementById("btn");
    alert(btnElt);//object HTMLInputElement
}
</script>
<input type="button" id="btn" value="hello"/>
```

## DOM编程案例

```html
<script type ="text/javascript">
window.onload =function(){var btnElt =document.getElementById("btn");btnElt.onclick = function(){/*
//获取username节点
var usernameElt= document.getElementById("username");
var username =usernameElt.value;
alert(username);
*/
alert(document.getElementById("username").value);
</script>
<!--
<input type="button" id="btn" .value="he
-->
<input type="text" id="username" /><input type="button" value="获取文本框的value" id="btn"/>
```

可以获取文本框中的值或者修改文本款的值

```html
<script type="text/javascript">
window.onload =function(){
document.getElementById("setBtn").onclick = function(){
document.getElementById("username2").value = document.getElementById("username1").value;
	}
}
</script>
<input type="text" id="username1" /><br>
<input type="text" id="username2" />
<br>
<input type="button"value="将第一个文本框中的value赋值到第二个文本框上"id="setBtn" />
```

 

```html
<!--blur事件:失去焦点事件-->
<!--以下代码中的this代表的是当前input节点对象,this.value就是这个节点对象的value属性。-->
<input type="text" onblur="alert(this.value)” />
```

### innerHTML和innerText操作div和span

<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
    <title>D0M编程-innerHTML和innerText操作div和span</title>
    <style type="text/css">
    #div1{
background-color:aquamarine;
width:300px;
height:300px;
border:1px black solid;
        position:absolute;
        top:100px;
        left: 100px;
    }
</style>
</head>
<body>
    <script type="text/javascript">window.onload =function(){
var btn = document.getElementById("btn");
btn.onclick = function(){
          //设置div的内容
    	//第一步：获取div对象
var divElt = document.getElementById("div1");
// 第二步:使用innerHTML属性来设置元素内部的内容
//divElt.innerHTML="fjdkslajfkdlsajkfldsjaklfds";
// divElt.innerHTML ="<font color='red'>用户名不能为空!</font>";
divElt.innerText ="<font color='red'>用户名不能为空!</font>";
        }                                     }
</script>
<input type="button" value="设置div中的内容"id="btn"/>
<div id="div1"></div>
</body>
</html>

innerText和innerHTML属性有什么区别?
相同点: 都是设置元素内部的内容。
不同点:

- innerHTML会把后面的“字符串”当做一段HTML代码解释并执行。
- innerText，即使后面是一段HTML代码，也只是将其当做普通的字符串来看待。

### 正则表达式

> 1、什么是正则表达式，有什么用?
> 正则表达式:Regular Expression正则表达式主要用在字符串格式匹配方面，
> 2、正则表达式实际上是一门独立的学科，在]ava语言中支持，c语言中也支持，javascript中也支持。大部分编程语言都支持正则表达式。正则表达式最初使用在医学方面，用来表示神经符号等。目前使用最多的是计算机编程领域，用作字符串格式匹配。包括搜索方面等。

**需要掌握:**

第一:常见的正则表达式符号要认识。
第二:简单的正则表达式要会写。
第三:他人编写的正则表达式要能看懂。
第四:在javascript当中，怎么创建正则表达式对象!(new 对象)
第五:在javascript当中，正则表达式对象有哪些方法!(调方法)

第六:要能够快速的从网络上找到自己需要的正则表达式。并且测试其有效性。

#### 常见的正则表达式符号

- .匹配除换行待以外的任意字符
- \w匹配字母或数字或下划线或汉字
- \s匹配任意的空白符
- \d匹配数字
- \b 匹配单词的开始或结束
- ^匹配字符串的开始
- $匹配字符串的结束
- \W 匹配任意不是字母，数字，下划线，汉字的字符
- \S匹配任意不是空白符的字符
- \D匹配任意非数字的字符
- \B 匹配不是单词开头或结束的位置
- [^x] 匹配除了x以外的任意字符
- [^aeiou] 匹配除了aeiiou以外的任意字符



- *: 重复零次或更多次
- +: 重复一次战更多次
- ?: 重复零次或一次
- {n}:  重复n次
- {n,}: 重复n次或更多次
- {n,m}:  重复n到m次



正则表达式当中的小括号()优先级较高。
[1-9]表示1到9的任意1个数字(次数是1次)

[A-Za-z0-9]表示A-Za-z0-9中的任意1个字符
[A-Za-z0-9-]表示A-2、a-z、0-9、-，以上所有字符中的任意1个字符。

|:表示或者

#### 简单的正则表达式

```javascript
QQ号的正则表达式:[1-9][0-9]{4,}$//第一位1-9 后面的随意
```

#### 他人编写的正则表达式要能看懂。

```javascript
email正则:^\w+([-+.]\w+)*@\w+([-.]\w+)*\\w+([-.]\w+)*$
```

#### 怎么创建正则表达式对象

第一种创建方式:

```javascript
var regExp =/正则表达式/flags;
```

第二种创建方式:使用内置支持类RegExp

```javascript
var regExp = new RegExp("正则表达式","flags");
```

关于flags:

g:全局匹配

i:忽略大小写

m:多行搜索(ES规范制定之后才支持m)当前面是正则表达式的时候m不能用，只有前面是字符串的时候才能用m

正则表达式对象的test()对象

true /false =正则表达式对象.test(用户填写的字符串);

true :字符串格式匹配成功

false:字符串格式匹配失败

```html
<script type="text/javascript">
window.onload =function(){
document.getElementById("btn").onclick = function(){
var email = document.getElementById("email").value;var emailRegExp = /^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$/;var ok =emailRegExp.test(email);
    if(!ok){
document.getElementByid("emailError").innerText ="邮箱地址不合法"; 
    }
}
}
</script>

<input type="text" id="email"/>
<span id="emailError" style="color: red; font-size: 12px;"></span>
<br>
<input type="button" value="验证邮箱"id="btn" />
```



## 复选框的全选和取消全选

**全选,取消全选**

```html
<script type="text/javascript">
window.onload =function(){
var firstChk = document.getElementById("firstchk");
firstChk.onclick =function(){
var aihaos =document.getElementsByName("aihao");
for(var i =0;i< aihaos.length; i++){
aihaosli].checked =firstChk.checked;
		}
	}
    
    //遍历每一个复选框
    for(var i=0;i<aihaos.length; i++){aihaos[i].onclick =function(){var checkedCount=0;// 总数量和选中的数量相等的时候,第一个复选框选中
for(var i=0;i< aihaos.length; i++){
if(aihaos[i1.checked)fcheckedCount++;
	}
firstChk.checked =(all == checkedCount);                                                         }
</script>
<input type="checkbox" id="firstChk"/><Br><input type="checkbox" name="aihao" value="smoke" />抽烟<Br>
<input type="checkbox" name="aihao" value="drink" />喝酒<Br>
<input type="checkbox" name="aihao" value="tt" />烫头<Br>
```

---

## 获取下拉列表选中项的value

```html
<script type="text/javascript">window.onload =function(){
        var provinceListElt= document.getElementById("provinceList");
        provinceListElt.onchange =function(){
        //获取选中顶项的value
            alert(provincelistElt.value);
    }
                                                        }
</script>
    <select id="provincelist">
	<option value="">--请选择省份--</option)
	<option value="001">河北省</option>
	<option value="002">河南省</option)
	<option value="003">山东省</option>
	<option value="004">山西省</option>
</select>
```

----

## 显示网页时钟

document.wirite(times);//打印在网页上

alert();//弹窗

```html
<script type="text/javascript">
/*
关于JS中内置的支持类:Date，可以用来获取时间/日期。
*/
// 获取系统当前时间
var nowTime = new Date();
// 输出
//document.write(nowTime);
//转换成具有本地语言环境的日期格式
nowTime = nowTime.toLocaleString();
document.write(nowTime);
document.write("<br>");
document.write("<br>");
//当以上格式不是自己想要的,可以通过日期获取年月日等信息,自定制日期格式
var t=new Date();
var year =t.getFullYear();// 返回年信息,以全格式返回
var month=t.getMonth();//月份是:0-11// 
var dayOfWeek=t.getDay();// 获职的一周的第几天(0-6)
var day =t.getDate();//获取日信息.
document.write(year+"年"+(month+1)+"月"+ day +“日");
//如何获取毫秒数
var times = t.getTime();
document.wirite(times);//打印在网页上
</script>
```

**使得页面时钟不断改变以及停止**

```html
<script type="text/javascript">
function displayTime(){
var t=new Date();
var year =t.getFullYear();// 返回年信息,以全格式返回
var month=t.getMonth();//月份是:0-11
var day =t.getDate();//获取日信息.
document.write(year+"年"+(month+1)+"月"+ day +“日");
}
//每隔1秒调用displayTime()函数
function start(){
//从这行代码执行结束开始,则会不间断的,每隔1000毫秒调用一次displayTime()函数
v = window.setInterval("displayTime()"，1000);
}
function stop(){
window.clearInterval(v);
}
</script>
<br><br>
<input type="button" value="显示系统时间"onclick="start();"/><input type="button" value="系统时间停止"onclick="stop();” /><div id="timeDiv"></div>
```

## 内置支持类Array

**第一种方法(比较常用)**

```html
<script type="text/javascript">// 创建长度为0的数组
var arr =[];alert(arr.length);
// 数据类型随意
var arr2 =[1,2,3,false,"abc",3.14];
alert(arr2.length);
//下标会越界吗
arr2[7]="test"
document.write("<br>");
// 遍历
for(var i=0;i< arr2.length; i++){document.write(arr2[i]+""<br>"");
}
</script>
```

JS中数组可以自动扩容

中间没有传值的默认undefined

第二种方法

```javascript
//另一种创建数组的对象的方式
var a = new Array();alert(a.length);//0
var a2= new Array(3);// 3表示长度
alert(a2.length);
var a3 = new Array(3,2);
alert(a3.length);//2 
```

**方法**

join(" ")连接

push()在末尾添加元素(数组长度+1)

pop()将末尾元素弹出(数组长度-1)

reverse()反转数组

```javascript
var a =[1,2,3,9];
var str = a.join("_");alert(str);//“1-2-3-9

//在数组的末尾添加一个元素(数组长度+1)
a.push(10);alert(a.join("_"));
// 将数组末尾的元素弹出(数组长度-1)
var endElt =a.pop();
// 在数组的末尾添加一个元素(数组长度+1)a.push(10);
alert(a.join("_"));
// 将数组末尾的元素弹出(数组长度-1)
var endElt =a.pop();alert(endElt);
alert(a.join("_"));

// push压栈
// pop弹栈
//·反转数组
a.reverse();
alert(a.join("-"));
```

==注意:s中的数组可以自动模拟栈数据结构:后进先出,先进后出原则.==

---

## ==设置table的tbody==

```javascript
var data = {
"total" : 4 ,
"emps" : [
{"empno" :7369,"ename":"SMITH","sal":800.0},
{"empno" :7361,"ename":"SMITH2","sal":1800.0},
{"empno" :7360,"ename" :"SMITH3","sal":2800.0},
{"empno":7369,"ename":"SMITH4","sal":3800.0}
]
};

window.onload =function(){
var displayBtnElt=document.getElementById("displayBtn");
displayBtnElt.onclick=function(){var emps =data.emps;
var html= "”
for(var·i=0;i<emps.length;·i++){
var emp=emps[i];
html += "<tr>”;
html +="<td>"+emp.empno+"</td>";
html +="<td>"+emp.ename+"</td>";
html +="<td>"+emp.sal+"</td>";
html+="</tr>";
document.getElementById("emptbody").innerHTML = html;//emptbody为tbody的id 可以往tbody中传入html语句
```



