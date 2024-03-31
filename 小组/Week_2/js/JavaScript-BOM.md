# BOM(浏览器对象模型)

关闭浏览器窗口、打开一个新的浏览器窗口、后退、前进、浏览器地址栏上的地址等，都是B0M编程。

---



## open和close

```html
<script type="text/javascript">
1、BOM编程中，window对象是顶级对象，代表浏览器窗口2、window有open和close方法，可以开启窗口和关闭窗口
术
</script>
<input type="button" value="开启百度(新窗口)"onclick="window.open('http://ww.baidu.com');" />
<input type="button" value="开启百度(当前窗口)"onclick="window.open('http://www.baidu.com',' self');" />
<input type="button" value="开启百度(新窗口)"onclick="window.open('http://www.baidu.com',' blank');"/>
<input type="button" value="开启百度(父窗口)" onclick="window.open('http://www.baidu.com','_parent');"/>
<input type="button" value="开启百度(顶级窗口)"onclick="window.open('http://www.baidu.com',，'top');"/>
<input type="button" value="关闭当前窗口" onclick="window.close();"/>
```

## 弹出消息框和确认框

```html
<script type="text/javascript">
function del(){
/*
var ok = window.confirm("亲，确认删除数据吗?");
if(ok){
alert("delete data ....");
}
*/
if(window.confirm("亲，确认删除数据吗?")){
    alert("delete data ....");
}
</script>
<input type="button" value="弹出消息框”onclick="window.alert('消息框!')” />

<!--删除操作的时候都要提前先得到用户的确认。-->
<input type="button" value="弹出确认框(删除)"onclick="del();” />
```

---

## history对象

```html
<input type="button" value="后退" onclick="window.history.back()" />
<input type="button" value="后退" onclick="window.history.go(-1)" />
<input type="button" value="前进" onclick="window.history.go(1)" />
```

---

## 设置浏览器地址栏的URL

```html
<script type="text/javascript">
    function goBaidu(){
var locationObj = window.location;
location0bj.href ="http://www.baidu.com";

window.location.href = "http://www.jd.com";

window.location ="http://www.126.com";

document.location.href="http://www.sina.com.cn"；
document.location ="http://www.tmall.com";
</script>
<input type="button" value="新浪" onclick="goBaidu();"/>
```

**总结有哪些方法可以通过浏览器往服务器发请求：**

1. 表单form的提交。
2. 超链接。<a href="http://localhost:8088/oa/save?username=zhangsan&password=123">用户只能点击这个超链接</a>
3. document.location
4. window.location
5. window.open("url")

直接在浏览器地址栏上输入URL，然后回车。
以上所有的请求方式均可以携带数据给服务器，只有通过表单提交的数据才是动态的。

## 将当前窗口设置为顶级窗口

```javascript
if(window.top != window.self){
    //将当前窗口设置为顶级窗口
window.top.location = window.self.location;
}
// window.top就是当前窗口对应的顶级窗口
// window.self表示当前自己这个窗口
```

# JSON

JavaScript Object Notation.(数据交换格式)

**主要作用:一种标准的数据交换格式.**

JSON是一种标准的轻量级的数据交换格式。特点是:体积小，易解析。

在实际的开发中有两种数据交换格式，使用最多，其一是JSON，另一个是XML。

XML体积较大，解析麻烦，但是有其优点是:语法严谨。(通常银行相关的系统之间进行数据交换的话会使用XL。)

HTML和XML有一个父亲:SGML(标准通用的标记语言。)EIM主要做页面展示:所以语法松散。很随意。x主要做数据存储和数据描述的:所以语法相当严格。

## 创建对象

```javascript
//创建JSON对象(JSON也可以称为无类型对象。轻量级，轻巧。体积小。易解析。)
var studentObj= {
    "sno":"110",
    "sname":"张三",
	"sex":"男"
}
//访问JSON对象的属性
alert(studentObj.sno + "," + studentObj.sname + "," + studentObj.sex);
```

**创建JSON数组**

```javascript
var students ={
{"sno":"110","sname":"张三","sex":"男"},
{"sno":"120","sname":"李四","sex":"男"},
{"sno":"130","sname":"王五","sex":"男"}
};
// 遍历
for(var i=0;i<students.length; i++){
var stuObj= studentsi];alert(stuObj.sno +","+ stu0bj.sname +","+ stuObj.sex);
}
```

JSON的语法格式:

```javascript
var jsonObj={
"属性名":属性值,
"属性名":属性值，
"属性名":属性值，
"属性名":属性值，
....
};
```

**复杂一些的 JSON 对象**

```javascript
var user ={
"usercode" : 110,
"username" :"张三"
"sex" : true,
"address" :{
"city":"北京”，
"street":"大兴区",
"zipcode" :"12212121",
};
"aihao" : ["smoke","drink","tt"]
alert(user.address.city)//访问对象居住城市
```

## ==eval函数==

可以将字符串当作一段JS代码解释并执行

```javascript
window.eval("var i =100;");
alert("i = " + i);//i = 100
```

使用例子

```javascript
fromJava ="var jsonqj ={\"name\":\"zhangsan\",\"password\":\"123\"}";
//这是java程序给发过来的json格式的"字符串"
//将以上的json格式的字符岭转换成json对象

window.eval("var fisonObi="+ fromJava);
alert(jsonObj.name + " ," + jsonObj.password);
```

java连接数据库,查询数据之后,将数据在java程序中拼接成]S0N格式的“字符串”,将json格式的字符串响应到浏览器

也就是说java响应到浏览器上的仅仅是一个"JSON格式的字符串",还不是一个json对象.

可以使用eval函数,将json格式的字符串转换成json对象.var 

## 一道面试题

在Js当中:[]和{}有什么区别?
[]是数组。
{}是JSON。

java中的数组:int[ ]arr ={1,2,3,4,5};

JS中的数组:var arr =[1,2,3,4,5];
JSON:var jsonObj = {"email":"zhangsan@123.com","age":25};