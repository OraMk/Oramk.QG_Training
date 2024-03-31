# HTML

## HTML的基本标签

```html
<!--1.这是html 的注释
	2.以下代码加上就是html5.0
-->
<!doctypy html>
<!--根-->
<html>
	<!--头-->
	<head>
		<!--网页的标题，显示在网页左上角
		<title>网页标题</title>
	</head>
	<!--体-->
	<body>
		网页的主题内容，欢迎学习HTML！
	</body>
</html>
```

<></>配套使用

分段落的用 <p></p>

<h1> 标题的用 </h1>

<h2>  标题的用</h2>

<h3>标题的用  </h3>

<h4>标题的用  </h4>

<h5> 标题的用 </h5>

换行 <br>

<!--换行标记是一个独目标记-->

横线<hr>

 更改横线的颜色和宽度<hr color="red" width="50%">

 双引号可以改成单引号<hr color='green' width=30%>

预留格式<pre></pre>

```html
<pre>
 for(int i = 0 ; i< 10 ; i++){
	System.out.println("i = " + i);
}
</pre>
```

<del>删除字</del>

<ins>插入字</ins>

<b>粗体字</b>

<i>斜体字</i>

10<sup>2</sup>

10<sub>m</sub>

<!--字体标签-->

<font color ="red" size="50">字体标签</font>

---



## 实体标签

b<a>c<!--错误的-->

<!--实体符合特点是：以&开始，以;结束。&lt;是小于号，&gt;是大于号-->

b&lt;a&gt;c

a&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bc

<!--空格为&nbsp;-->

----



## HTML表格

### 表格的基本用法

table 表示表格 tr表示一行 td表示一个单元格(点击表格查看代码)

<!--border="1px"设置表格的边框为1像素宽度-->
<!--width="300px"设置表格整体宽度为300像素-->

<!--width="60%"设置表格整体宽度为占整体的60%-->

<!--height="150px"设置表格整体高度为150像素-->

<!--align对齐方式-->

<!--<center></center>可以让中间的数据居中-->

<center>表格</center>

<table align="center" border='1px' width="60%" height="150px">
	<tr align="center">
        <td>a</td><!--一个单元格-->
        <td>b</td><!--一个单元格-->
        <td>c</td><!--一个单元格-->
    </tr><!--一行-->
    <tr>
        <td>d</td><!--一个单元格-->
        <td>e</td><!--一个单元格-->
        <td>f</td><!--一个单元格-->
    </tr><!--一行-->
    <tr>
        <td >x </td><!--一个单元格-->
        <td>y</td><!--一个单元格-->
        <td align="center" >z</td><!--一个单元格-->
    </tr><!--一行-->
</table>

----

### 单元格合并

<table align="center" border='1px' width="60%" height="150px">
	<tr>
        <td>1</td><!--一个单元格-->
        <td>2</td><!--一个单元格-->
        <td>3</td><!--一个单元格-->
    </tr><!--一行-->
    <tr>
        <td>a</td><!--一个单元格-->
        <td>b</td><!--一个单元格-->
        <td rowspan="2">cf</td><!--一个单元格-->
    </tr><!--一行-->
    <tr>
        <td colspan="2">d</td><!--一个单元格-->
    </tr>
</table>

让第二行的第三个与第三行的第三个合并（单元格）

==一般将下面的单元格删除，然后在上面的单元格<tr>中加速 rowspan="n"n为多少就合并多少格==

==合并左右的通过colspan="n"n为多少就合并多少格==

==此处没有上下之分删除左右哪个都可以==

rowspan 合并



> th标签

<th>可以将单元格居中加粗，依旧为单元格标签，一般用于第一行

<table align="center" border='1px' width="60%" height="150px">
	<tr align="center">
        <th>a</th>
        <th>b</th><!--此处改变了td为th--->
        <th>c</th>
    </tr><!--一行-->
    <tr>
        <td>d</td><!--一个单元格-->
        <td>e</td><!--一个单元格-->
        <td>f</td><!--一个单元格-->
    </tr><!--一行-->
    <tr>
        <td >x </td><!--一个单元格-->
        <td>y</td><!--一个单元格-->
        <td align="center" >z</td><!--一个单元格-->
    </tr><!--一行-->
</table>

---



### 表格的切割(thead tbody tfoot)

thead tbody tfoot 在table中不是必须的，只是这样做便于后期的JS代码的编写.

<table align="center" border='1px' width="60%" height="150px">
    <thead>
		<tr align="center">
       		<th>a</th>
   	     	<th>b</th><!--此处改变了td为th--->
       	 	<th>c</th>
    	</tr><!--一行-->
    </thead>
    <tbody>
    	<tr>
        	<td>d</td><!--一个单元格-->
        	<td>e</td><!--一个单元格-->
        	<td>f</td><!--一个单元格-->
    	</tr><!--一行-->
    </tbody>
    <tfoot>
        <tr>
            <td>x</td><!--一个单元格-->
            <td>y</td><!--一个单元格-->
            <td>z</td><!--一个单元格-->
        </tr><!--一行-->
    </tfoot>
</table>

==注意切割后不同部分的表格不能合并==

---



## 更改背景颜色与图片

<meta charset="GBK">
该代码告诉浏览器以GBK编码的方式打开

<body bgcolor="red" background="C:\Users\86178\Desktop\OIP-C.jpg">

bgcolor="red"背景颜色

background="" 更改背景图片"填入图片文件的路径"

---



## 图片

<img src = "C:\Users\86178\Desktop\OIP-C.jpg" width="100px"/>

<br><br><br>

<img src = "C:\Users\86178\Desktop\OIP-C.jpg" width="200" title="我是百度图片" alt= "图片找不到喔"/>

使用&lt;img src="" width=" px"/&gt;来插入图片控制宽度

最好不要用height=""控制高度容易使得图片失真

img就是图片标签

src就是图片路径

title设置鼠标悬停时显示的信息

alt用来设置图片加载失败时显示的信息

<></>当中间没有内容时候可以写成<    />

---



### 超链接/热链接==

<a href="http://www.baidu.com">百度</a>

&lt;a href="填入网页链接"&gt;此处写显示的名字&lt;a/&gt;

<!--

href: hot references 热引用

href属性后面一定是一个资源的地址。



href后面的路径可以是绝对路径也可以是相对路径，可以是某个网络资源的路径也可以是本地资源的路径

-->

超链接特点:

有下划线 鼠标停留在超链接上显示小手形状

```html
<a href="http://www.baidu.com">

​	<img src="OIP-C.jpg">

</a>
```

<a href="http://www.baidu.com"><img src="OIP-C.jpg"></a>

<img src="OIP-C.jpg">

在&lt;a href="http://www.baidu.com"&gt;中加入targt=""可以更改点击后是在当前页面打开还是新建页面打开

_self为当前页面打开

_blank：新窗口

_top:顶级窗口

_parent：父窗口

超链接的作用：

​	通过超链接可以从浏览器向服务器发送请求。

​	浏览器向服务器发送数据（请求：request）

​	服务器向浏览器发送数据（响应：response）

B/S结构的系统:每一个请求都会对应一个响应

B--请求----->S

S---响应---->B

用户点击超链接和用户在浏览器地址栏上直接输入URL，有什么区别?

本质上没有区别，都是向服务器发送请求。从操作上来讲，超链接使用更方便。

---



## 列表

### 无序列表

<ul>
    <li>中国</li>
    	<ul>
           <li>北京</li>	
            	<ul>
                	<li>东城区</li>
                    <li>西城区</li>
                    <li>朝阳区</li>
            	</ul>
            <li>上海</li>
    	</ul>
    <li>美国</li>
    <li>英国</li>
</ul>

&lt;ul&gt;

&lt;li&gt;    &lt;/li&gt;

&lt;li&gt;    &lt;/li&gt;

&lt;/ul&gt;

&lt;ul type=""&gt;

type后可以改变序列的格式

circle圆圈

square方框

disc圆

### 有序列表

<ol>
    <li>水果</li>
    	<ol type="a">
            <li>西瓜</li>
            <li>苹果</li>
    	</ol>
    <li>蔬菜</li>
    <li>甜点</li>
</ol>

&lt;ol type=""&gt;

type

a 小写字母

A 大写字母

---



## ==表单(form)==

### 基本语法

1、表单有什么用?

收集用户信息。表单展现之后，用户填写表单，点击提交按钮提交数据给服务器

2、怎么画一个表单?

使用form标签画表单。

3、一个网页当中可以有多个表单form。

<form action="http:www.baidu.com">
<!--画一个提交按钮，用来提交表单-->
<!--按钮可以用input输入域 type="submit"的时候表示该按钮是一个提交按钮，具有提交表单的能力"-->
<input type="submit" value = "注册">
<!--这是一个普通按钮，不具备提交表单的能力-->
<input type="button" value ="用来设置文本">
</form>

<form>表单标签

表单最终是需要提交数据给服务器的，form标签有一个action属性，这个属性用来指定服务器地址:

action属性用来指定数据提交给哪个服务器。

action属性和超链接中的href属性一样。都可以向服务器发送请求(request)

http://192.168.111.3:8080/oa/save 这是请求路径，表单提交数据最终提交给:192.168.111.3机器上的8080端口对应的软件。

==在action 后加上 method="post"可以隐藏输入的数据（不在网址上显示）==

form表单method属性(默认get):

get:采用get方式提交的时候，用户提交的信息会显示在浏览器的地址栏上。

post:采用post方式提交的时候，用户提交的信息不会显示在浏览器地址栏上。当用户提交的信息中含有敏感信息，例如:密码，建议采用bost方式提交。

<!--超链接也可以提交数据给服务器，但是提交的数据都是固定不变的。-->
<!--超链接是get请求。不是post请求。-->

post提交的时候提交的数据格式和get还是一样的，只不过不再地址栏上显示出来

<type = "" > 

- **submit表示提交** 
- **button是普通按钮** 
- **text 文本框** 
- **password 密码框** 
- **checkbox 复选框** 
- **radio 单选框(当name相同时候只能选择一个)**

checkbox 复选框和单选按钮的value 必须手动设置

在radio 与checkbox后添加check 为默认选中

对于按钮来说按钮上的value 属性用来指定按钮上的文本信息

超链接和表单都可以向服务器发送请求，只不过表单发送请求的同时可以携带数据

<form>
    <center>用户名<input type="text"></center>
    <br>
    <center>密码<input type="password"></center>
    <br>
    <center><input type="submit" value = "提交"></center>
</form>




<form>
​    

<form><table>
    <tr>
    <td>用户名</td>
    <td><input type="text" name="username"></td>
    </tr>
    <tr>
        <td>密码</td>
        <td><input type="password" name="userpwd" ></td>
    </tr>
    <tr>
        <td colspan="2"><center><input type="submit" value = "提交"/>
            &nbsp;&nbsp;&nbsp;
            <input type="reset" value = "清空"/></center></td>
    </tr>
</table></form>

对于input需要给name赋值查看上表单



表单是以什么格式提交数据给服务器的?

http://localhost:8080/jd/login?username=abc&userpwd=111
格式:action?name=value&name=value&name=value&name=value&name=value...HTTP协议规定的，必须以这种格式提交给服务器。

==强调:表单项写了name属性的，一律会提交给服务器。不想提交这一项，就不要写name属性。==

文本框和密码框的value不需要程序员指定，用户输入什么value就是什么。

选择框<select> 与<option>并用

<select name="grade">
    <option value="gz">高中</option>
    <option value="dz">大专</option>
    <option value="bk" selected>本科</option>
    <option value="ss">硕士</option>
</select>

selected 默认选中

文本框<textarea>

<textarea row="10" cols="60" name="introduce"></textarea>

### 下拉列表可以多选

<!--multiple="multiple"支持多选 size="2"设置显示条数-->

<select multiple="multiple" size="2">
    <option>广东省</option>
    <option>广西省</option>
    <option>湖南省</option>
    <option>福建省</option>
</select>

### file控件

<input type="file"/>

type写file可以选择文件

<!--file控件文件上传专用-->

### hidden 控件

type="hidden"

<!---隐藏域，网页上看不到，但是表单提交的时候数据会自动提交给服务器-->

<input type="hidden" name="userid" value="111"/>

### readonly和disabled

<form>
    用户代码<input type="text" name="usercode" value="110" readonly/> <br>
    用户姓名<input type="text" name="username" value = "zhangsan" disabled/>
</form>
==readonly和disabled相同点:都是只读不能修改。
readonly可以提交给服务器，disabled数据不会提交(即使有name属性也不会提交。)==

### maxlength

用来控制文本框中可输入的字符数量

<input type="text" maxlength="3"></input>

## HTML中元素的ID属性

1、在HTML文档当中，任何元素（节点）都有ID属性，id属性是该节点的唯一标识.所以在同一个HTML文档当中[d值不能重复。

2、ID就是节点的身份证号，不能重复

注意:表单提交数据的时候，只和name有关系，和id无关。

3、ID的作用:便于定位元素(节点)

4、HTML文档是一棵树，树上有很多节点，每一个节点都有唯一的id。

<form id="myform">
<input type="text" id="username" name="username"/><input type="password" id="userpwd" name="userpwd"/>

javascript主要就是D0M树上的节点进行增删改的。
DOM(Document)树。

## DIV和span

div和spqn都可以称为”图层“

图层的作用是为了保证页面可以灵活的布局

现代网页开发中div布局使用最多

<div id="div1">我是一个div<div id="div2">我是一个div</div>

```html
<span id="span1">我是一个span的标签</span> <span id="span2">我是一个span的标签</span>
```

div会独自占一行（默认情况下）

span不会独自占一行

div可以嵌套

<div id="3">
    <div>
        <div>test</div>
    </div>
</div>
