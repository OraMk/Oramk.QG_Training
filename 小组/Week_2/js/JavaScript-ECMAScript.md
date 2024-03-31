# JavaScript-ECMAScript(基础语法)

JavaScript是运行在浏览器上的脚本语言，简称JS。

Javascript这个名字中虽然带有"Java"但是和Java没有任何关系，只是语法上有点类似。他们运行的位置不同，Java运行在IM当中，Javascript运行在浏览器的内存当中。

Javascript程序不需要我们程序员手动编译，编写完源代码之后，浏览器直接打开解释执行。
Javascript的"目标程序"以普通文本形式保存，这种语言都叫做"脚本语言"。

---

## HTML中嵌入JS代码

### 第一种方式

<form action="http:www.baidu.com">
<input type="button" value="hello" onclick="window.alert('hello.js')"/>        <input type="button" value="hello" onclick='window.alert("hello.jscode")'/>
   <input type="button" value="hello" onclick="window.alert('hello zhangsan') window.alert('hello lisi') window.alert('hello wangwu')"/>
</form>



Js是一门事件驱动型的编程语言，依靠事件去驱动，然后执行对应的程序。在Js中有很多事件，其中有一个事件叫做:鼠标单击，单词:click。并且任何事件都会对应一个事件句柄叫做:onclick。【注意:事件和事件句柄的区别是:事件句柄是在事件单词前添加一个on。】，而事件句柄是以HT标签的属性存在的。

onclick="js代码"，执行原理是：页面打开的时候，js代码并不会执行，只是把这段JS代码注册到按钮的click事件上了。等这个按钮发生c1ick事件之后，注册在onclick后面的js代码会被浏览器自动调用。

==怎么使用Js代码弹出消息框?
在Js中有一个内置的对象叫做window，全部小写，可以直接拿来使用，window代表的是浏览器对象。
window对象有一个函数叫做:alert，用法是:window.alert("消息");这样就可以弹窗了。==

==window.可以省略不写==

JS中的字符串可以使用双引号，也可以使用单引号.

JS中的一条语句结束后可以使用“；”也可以不用.

### 第二种方式

<!--脚本块方式-->

<script type="text/javascript">
    window.alert("Hellow World")
    /*
    	暴露在脚本快当中的程序，在页面打开的时候执行
    	并且遵循自上而下的顺序依次逐行执行（这个代码
    	执行不需要事件）
    */
</script>

JavaScript脚本块在一个页面可以出现多次，随意

出现的位置也是随意的

JS代码的注释//为单行注释 /* */多行注释

==alert函数有阻塞当前页面的加载的作用，直到用户点击确定==

在脚本快中&lt;script&gt;  &lt;/script&gt;

中间写的程序会执行

### 第三种方式

<!--在需要的位置引入js脚本文件-->

<script type="text/javascript" src="1.s"></script>

src=输入js文件的路径

js文件中的代码遵循自上而下的顺序依次逐行执行

<!--同一个js文件可以呗引入多次，但是实际开发中这种需求很少-->

不能将上述代码写成

<script type="text/javascript" src="1.s"/>

在引入脚本文件中&lt;script&gt;  &lt;/script&gt;

中间写的程序不会执行

---

## 变量

代码如下

<!DOCTYPE heml>
    <html>
        <head>
            <title>js变量</title>
        </head>
        <body>
            <script type="text/javascript">
                <!--声明变量 var 变量名-->
                var i = 100;
                i = false;
                i ="abc";
                i =new Object();
                i = 3.14;
                var i ;
                alert("i =" + i);
            </script>
        </body>
</html>
</!doctype>



java中要求变量声明的时候是什么类型，以后永远都是这种类型，不可变。编译期强行固定变量的数据类型。
称为强类型语言。

javascript当中的变量?
怎么声明变量?
var 变量名怎么给变量赋固?
变量名 = 值;javascript是一种弱类型语言，没有编译阶段，一个变量可以随意赋值

在JS当中，当一个变量没有手动赋值的时候，默认赋值undefined 是一个具体存在的值

alert(age);一个变量没声明直接访问是语法错误，不能这么写

==当一个变量声明的时候没有使用var关键字，那么不管这个变量在哪里声明的都属于全局变量==

### 局部变量

> 在函数体当中声明的变量，包括一个函数的形参都属于局部变量，局部变量的生命周期是:函数开始执行时局部变量的内存空间开辟，函数执行结束之后，局部变量的内存空间释放。局部变量生命周期较短。

### 全局变量

> 在函数体之外声明的变量属于全局变量，生命周期：
> 浏览器打开时声明，浏览器关闭时销毁，尽量少用。因为全局变量会一直在浏览器的内存当中，耗费内存空间。
> 能使用局部变量尽量使用局部变量。

---

## JS函数

<!DOCTYPE heml>
    <html>
        <head>
            <title>js变量</title>
        </head>
        <body>
            <script type="text/javascript">
            </script>
        </body>
</html>
</!doctype>

JS函数等同于java语言中的方法，函数也是一段可以被重复利用的代码片段。函数一般都是可以完成某个特定功能的。

### 第一种方式

function 函数名（形参列表){

函数体;

}

```javascript
function sum(a,b){

alert(a+b);

}

sum(10,20);
```

<!--函数需要调用才能执行-->

<!--a和b都是局部变量，他们都是形参（a和b都是变量名,变量名随意)-->

var retValue2 = sum("jack");// jack赋值给a变量,b变量没有赋值系统默认赋值undefinedalert

(retValue2);<!--jackundefined-->

var retValue3=sum();

alert(retValue3);<!-- NaN(NaN是一个具体存在的值，该值表示不是数字。Not a Number)-->

var retValue4=sum(1，2，3);
alert("结果="+retValue4);<!--结果=3-->

### 第二种方式

函数名 = function(形参列表)

{

函数体；

}

```html
<html>
    <body>
        <script type="text/javascript">
        sayHello = function(username)
		{
		alert("hello" + username);
		}

		sayHellow("zhangsan");
           </script>
    </body>
    
</html>
```



<form action="http:www.baidu.com">
    <input type="button" value="hello" onclick="sayHello('jack')"/>
</form>



可以这样调用

JS当中的函数在调用的时候，参数的类型没有限制，并且参数的个数也没有限制。(弱类型)

JS不需要如果重名的话，后声明的函数会将前面声明的函数覆盖掉，无法进行重载 即JS中函数不能重名.

## 数据类型

> 原始类型

Undefined,Number,String,Boolean,Null

> 引用类型

Object以及Object的子类

==ES规范(ECMAScript规范)，在ES6之后，又基于以上的6种类型之外添加了一-种新的类型:Symbo1==

JS中有一个运算符 typeof ，这个运算符可以在程序运行阶段动态的获取变量的数据类型。

typeof 运算符的语法格式：

typeof 变量名
typeof运算符的运算结果是以下6个字符串之一:注意字符串都是全部小写,
"undefined"
number'"string
"boolean'
"object"
"function"

例如： 求和，要求a变量和b变量将来的数据类型必须是数字，不能是其他类型 因为以下定义的这个sum函数是为了完成两个数字的求和

```javascript
function sum(a,b)
{
if(typeof a == "number" && typeof b == "number"){
return a+ b;
}
alert(a + "," + b + "必须都为数字!");
}
```

```javascript
var i;
alert(typeof i);// "undefined"
var k=10;
alert(typeof k);// "number"
var f="abc";
alert(typeof f);// "string"
var d= null;
alert(typeof d);//"Object" null属于NULL类型
var flag =false;
alert(typeof flag);//"boolean"
function Hello{

}
alert(typeof Hello);//"function"
```

### Undefined

> 该类型只有一个值，undefined,当一个变量没有手动赋值，系统默认赋值undefined 也可以手动赋值undefined

var i;

var k= undefined;

var y ="undefined";

alert(i == k)//ture

alert(i == y)//false

### Number

Number类型包括:-1  0  1  2  2.3  3.14 100 ...  NaN Infinity

整数、小数、整数、负数、不是数字、无穷大都属于Number

NaN表示Not a Number ，不是一个数字，但是属于Number类型，运算结果应该是一个数字，但是最后算完不是一个数字的时候就是NaN

”+“号面对字符串会先进行字符串的拼接而非加法运算

Inifinity 当除数为0的时候，结果为无穷大

**isNaN函数**

isNaN(数据) ， 结果是true表示不是一个数字，结果为false表示是一个数字

```javascript
function sum(a, b)
{
if(isNaN(a)|| isNaN(b)){
alert("参与运算的必须是数字!");
return;
}
return a + b；
}
```

**parseInt()**函数可以将字符串自动转化成数字，并且取整位数

```javascript
alert(parseInt("3.9999"));//3
alert(parseInt(3.9999));//3
```

**parseFloat()**函数可以将字符串自动转化成数字

```javascript
alert(parseFloat("3.14")+1);//4.14
alert(parseFloat("3.2")+1);// 4.2
```

**Math.ceil()**函数 是个数学公式表示向上取整

```javascript
alert(Math.ceil("2.1"));//3
```

### Boolean

JS的boolean类型永远只有两个值，true和false

```javascript
var username =jack
if(username){
    <!--这里不用写boolean(username) 会自动将username 调用为boolean(username)-->
    alert("欢迎你"+ username);
}
else{
alert("用户名不能为空!");
}
```

在Boolean类型中有一个函数叫做Boolean(数据) 将非boolean类型转化为boolean

```javascript
alert(Boolean(1));// true
alert(Boolean(0));// false
alert(Boolean(""));// false
alert(Boolean("abc"));// true
alert(Boolean(null));// false
alert(Boolean(NaN));//false
alert(Boolean(undefined));//false
alert(Boolean(Infinity));// true
```

规律：”有“就转化为true，”没有“就转化为false

### Null

只有一个值null

==但是注意alert(null);结果为Object==

### String

1.在]s当中字符串可以使用单引号，也可以使用双引号。

var s1='abcdef';

var s2 ="test";

2.在Js当中，怎么创建字符串对象呢?

两种方式:第一种:==var s="abc";==
第二种(使用]S内置的支持类String):==vars2=new String("abc");==需要注意的是:string是一个内置的类，可以直接用，string的父类是Object。

```javascript
//小string（原始数据类型）
var x ="abc";
alert(x);//"String"
//大string（object类型）
var y = new String("abc");
alert(y);//"Object"
```

3、无论小string还是大string，他们的属性和函数都是通用的。

4、关于string类型的常用属性和函数?

常用函数:
length 获取字符串长度
indexOf 获取指定字符串在当前字符串中第一次出现处的索引
lastIndex0f获取指定字符串在当前字符串中最后一次出现处的索引
replace   替换
substr   截取子字符串
substring 截取子字符串
toLowerCase 转换小写
toUpperCase  转换大写
split      拆分字符串

```javascript
//获取字符串长度
aLertkx.Length);//4
alert(y.length);//3

//判断一个字符串是否包含某个字符串
alert("http://www.baidu.com".indexof("http"));//0
alert("http://www.baidu.com".indexOf("https"));//-1
//判断一个字符串是否包含某个字符串
alert("http://www.baidu.com".indexof("https")>=0 ?"包含":"不包含");

//replace(只替换第一个)
alert("name=value%name=value%name=value".replace("%","&"));//name=value&name=value%name=value
//继续调用replace方法,就会替换第“二”个.
//想全部替换需要使用正则表达式.
alert("name=value%name=value%name=value" .replace("%","&").replace("%",
"&"));//name=value&name=value&name=value
```

substr和substring

```javascript
//substr(startIndex,length)
alert("abcdefxz",substr(2,4))//cdef
//substring(startIndex, endIndex)
alert("abcdefxz",substring(2,4))//cdef
```

"    ".trim();去除前后空白的函数

```javascript
"  abc   ".trim();//"abc"
```



### Object

object类型是所有类型的超类，自定义的任何类型默认继承超类

属性

prototype属性(常用):作用是给类动态的扩展属性和函数

constructor属性

函数

tostring()

valueof()

toLocaleString()

5、在]s当中怎么定义类?怎么new对象?
定义类的语法:
第一种方式:function 类名(形参){
}

第二种方式:类名 = function(形参){

}
创建对象的语法:
new 类名(实参);//构造方法名和类名一样

区分:

```javascript
function say Hello{
}
sayHello();//当作函数
new sayHello();//把sayHello当作类来创建对象
```

JS中类的定义，同时又是一个构造函数的定义

在js中类的定义和构造函数的定义是放在一起完成的。

**第一种**

```javascript
function User(a,b,c)
{
this.son = a ;
this.sname = b ;
this.sage = c;
}
// 创建对象
var u1 = new User(111,"zhangsan",30);
// 访问对象的属性
alert(u1.sno);alert(u1.sname);alert(u1.sage);
var u2 = new User(222,"jackson",55);
alert(u2.sno);alert(u2.sname);
alert(u2.sage);
//访问一个对象的属性,还可以使用这种语法
alert(u2["sno"]);
alert(u2["sname"]);
alert(u2["sage"]);
```

**第二种**

```javascript
Emp = function(ename,sal)
{
 //属性
 this.ename = ename;
 this.sal = sal;
}
var el = new Emp("SMITH",800);
alert(el["ename"]+","+ e1.sal);
```



在属性中创建函数

```javascript
Product =function(pno,pname,price){// 属性
this.pno =pno;
this.pname = pname;this.price =price;// 函数
this.getPrice = function(){
return this.price;
}
}
var pro= new Product(111,"西瓜”，4.0);
var pri = pro.getPrice();
alert(pri);//4
```

可以通过prototype这个属性来给类动态扩展属性以及函数

```javascript
Product.prototype.getPname =function(){
return this.pname;
}
//调用后期扩展的getPname()函数
var pname =xigua.getPname();
alert(pname);
//给string扩展一个函数
String.prototype.suiyi =function(){
    alert("这是给string类型扩展的一个函数，叫做suiyi");
}
"abc".suiyi();
```

### null NaN undefined 区别

- null NaN undefined数据类型不一致
- null 和 undefined可以等同

```javascript
alert(null == NaN);//false
alert(null == undefined);// true
alert(undefined == NaN);// false
```

在JS当中有两个比较特殊的运算符

==(等同运算符:只判断值是否相等)

===(全等运算::既判断值是否相等，又判断数据类型是否相等)

```javascript
alert(null === NaN);//false
alert(null === undefined);// false
alert(undefined === NaN);// false
alert(1 === ture);// false
alert(1 == ture);// ture
```

---

## 事件

JS中的事件:

1. blur失去焦点

2. focus获取焦点
   
3. click鼠标单击

4. dblclick鼠标双击

   

5. keydown键盘按下

6. keyup键盘弹起
   
7. mousedown鼠标按下

8. mouseover鼠标经过

9. mousemove鼠标移动

10. mouseout鼠标离开

11. mouseup鼠标弹起
    
12. reset表单重置

13. submit表单提交
    
14. load页面加载完毕

15. change下拉列表选中项改变，或文本框内容改变

16. select文本被选定

任何一个事件都会对应一个时间句柄，事件句柄是在事件前添加on

onXXX这个事件句柄出现在一个标签的属性位置上。（事件句柄以属性的形式存在。）

### 注册事件的方式

**第一种:直接在标签中使用句柄**

```javascript
<input type="button" value="hello" onclick="sayHello()"/>
```

**回调函数**

对于当前程序来说,sayHello函数被称为回调函数(callback函数)
回调函数的特点:自己把这个函数代码写出来了,但是这个函数不是自己负责调用,由其他程序负责调用该函数.

**第二种:使用纯JS代码完成事件的注册**

```javascript
<input type="button" value="hel1o2"id="mybtn"/>
<script type="text/javascript">
function doSome(){
    alert("do some!");
}            
第二种注册事件的方式，是使用纯JS代码完成事件的注册。
来
//第一步:先获取这个按钮对象(document是全部小写，内置对象，可以直接用，document就代表整个HTML页面)
var btnObj= document.getElementById("mybtn");
//第二步:给按钮对象的onclick属性赋值
btnobj.onclick=dosome;//注意:千万别加小括号.btnobj.onclick= dosome();这是错误的写法.
<\script>
```

匿名函数

```javascript
var mybtn1 =document.getElementById("mybtn1");
mybtn1.onclick = function(){//这个函数没有名字,叫做匿名函数,这个匿名函数也是一个回调函数.
alert("test..........”);
}
```

---



## JS代码执行顺序

以下为错误代码

```html
<script type="text/javascript">
// 第一步:根据id获取节点对象
var btn = document.getElementById("btn");//返回nu11(因为代码执行到此处的时候id="btn"的元素还没有加载到内存)
// 第二步:给节点对象绑定事件
btn.onclick =function(alert("hello js");
</script>
<input type="button" value="hello" id="btn" />
</body>
```

可以使用onload加载页面元素改进

```html
<body onIpad="ready()">
<script type="text/javascript">
function ready(){var btn = document.getElementById("btn");btn.onclick =function(){
alert("hello js");
}
}
</script>
<input type="button" value="hello" id="btn" />
</body>
```

也可以用下面代码改进:

```html
<body>
<script type="text/javascript">
    //页面加载的过程中，将a函数注册给了load事件
    //页面加载完毕之后，load事件发生了，此时执行回调函数a
    //回调函数a执行的过程中,把b函数注册给了id="btn"的
    //click事件
    //当id="btn"的节点发生click事件之后
    //,b函数被调用并执行，
    window.onload =function(){//这个回调函数叫做a
        document.getElementById("btn").onclick={//这个回调函数叫做b
            Function(){alert("hello js");
	}
}
</script>
<input type="button" value="hello" id="btn" />
</body>
```

---



## 设置节点的属性

例如：更改type

```html
<body>
<script type="text/javascript">
window.onload =function(){
document.getElementById("btn").onclick = function(){
var mytext= document.getElementById("mytext");
    mytext.type ="checkbox";
	}
}
</script>
<input type="text" id="mytext"/>
<input type="button" value="将文本框修改为复选框"id="btn"/>
</body>
```

---

## 捕捉回车键

```javascript
usernameElt.onkeydown =function(event){
if(event.keyCode === 13){
alert("正在进行验证....");
}
}
```

13为键盘的key值

event为对文本框输入数值时接受到的“键盘事件对象” 可以用keyCode属性来获取键值

## 运算符

大部分跟java一样

### void(用来使得页面不跳转)

```html
<a href="javascript:void(0)"onclick="window.alert('test code')">既保留住超链接的样式，同时用户点击该超链接的时候执行一段S代码，但页面还不能跳转。
</a>
```

void运算符的语法:void(表达式)
运算原理:执行表达式，但不返回任何结果。

void不返回任何东西 可以使得href=""超链接失去路径即使得页面不跳转

javascript: 是为了告诉浏览器后面的是一段js代码

以上程序的javascript是不能省略的

## JS控制语句

> if  
>
> switch 
>
> while
>
>  do..while.. 
>
> for 
>
> break 
>
> continue

JS存在特殊的：

for ... in...语句(了解)

with语句（了解）

**创建JS数组**

**for ... in...**

```javascript
var arr = [false,true,1,2,,"a,b,c",3.14];//JS中数组中元素的类随意，个数也随意
//遍历数组
for(var i = 0; i < arr.length ;i++)
    {
        alert(arr[i]);
    }
//for..in
for(var i in arr){//i还是下标 跟java的增强for循环不一样
    alert(arr[i]);
}
```



```javascript
User =function(username,password){
this.username =username;
this.password =password;
}
//访问对象
var u= new User("张三"，"444");
alert(u.username + "," + u.password);
alert(u["username"]+ "," + u["password"]);
//for..in
for(var shuXingMing in u){
    alert(shuXingMing);//shuXingMing是一个字符串
    //访问对象 
    alert(u[shuXingMing]);
}
```

**with**

```javascript
alert(u.username + "," + u.password);//可以更改为如下:
with(u){
	alert(username + "," + password);
}
```

