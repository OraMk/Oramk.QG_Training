# CSS

CSS(Cascading Style Sheet) :层叠样式表语言

作用:修饰HTML页面。设置HTML页面中的某些元素的样式，让HTML页面更好看

好比是HTML的化妆品 主体是HTML CSS依赖HTML

## 在HTML页面中嵌套使用CSS的三种方式

### 内联定义

内联定义即是在标签内部使用style属性来设置元素的CSS样式

语法格式 :

​	<标签 style="样式名：样式值；样式名：样式值；样式名：样式值；...."</标签>

展示代码如下

<!doctype html>
    <html>
        <head>
            <title>内联定义</title>
        </head>
        <body>
            <div style="width :300px;height:300px; background-color: red; display : none ；border-color:red ;border-style:solid;border-width ： 1px；"
        </body>
	</html>
</!doctype>

<!--width宽度 height高度 background-color背景色样式 display 布局样式（none表示隐藏，block表示显示-->

border-color:red ;border-style:solid;border-width ： 1px；可以写成 border:1px solid red;

### 样式块方式.

在head标签中使用style块，这种方式被称为样式块方式.

语法格式:

<head>
    <style type="text/css">
    选择器{
        样式名：样式值
        样式名：样式值
        样式名：样式值
        ...
        }
        选择器{
        样式名：样式值
        样式名：样式值
        样式名：样式值
        ...
        }

    </style>

</h

展示代码如下

<!--设置样式字体大小为12px，颜色为红色-->

<!doctype html>
    <html>
        <head>
            <title>样式块方式</title>
            <style type ="text/css">
            /*
            	这是css的注释
            */
            /*
            	id选择器
            	语法格式
            	#id{
            		样式名：样式值;
            		样式名：样式值;
            		样式名：样式值;
            	}
            */
                #username{color:red;font-size:12px;}
            </style>
        </head>
        <body>
            <span id="username">对不起，用户名不能为空</span>
        </body>
	</html>

#### id选择器

​            	语法格式
​            	#id{
​            		样式名：样式值;
​            		样式名：样式值;
​            		样式名：样式值;
​            	}

#### **标签选择器:**

​	标签名{

​				样式名：样式值;

​				样式名：样式值;

​				样式名：样式值;

​				}

作用范围比ID选择器广

<!doctype html>
    <html>
        <head>
            <title>样式块方式</title>
            <style type ="text/css">
                div {
                    background-color:black;
                    border:1px solid red;
                    width:100px;
                    height:100px;
                }
            </style>
        </head>
        <body>
            <span id="username">对不起，用户名不能为空</span>
            <div> </div>
        <div></div><div></div>
    </body>
</html>

#### 类选择器:

.类名{

​				样式名：样式值;

​				样式名：样式值;

​				样式名：样式值;

​				}

代码如下

```html
<style type="text/css">
    .student{
    border:1px solid red;
        width: 400px;
        height : 10px
    }
</style>
<input type="text" class="student"/>
<select class="student">
    <option>专科</option>
    <option>本科</option>
</select>
```





### ==链入外部样式表文件==(最常见)

将样式写到一个独立的xxx.css文件当中，在需要的网页上直接引入css文件，样式就引入了.

语法格式:

​	<link type="text/css" rel="stylesheeet" href="css文件的路径"/>

这种方式易维护，维护成本较低.

<!doctype html>
    <html>
        <head>
            <title>在HTML中使用CSS样式的第三种方式 引入css文件</title>
            <!--引入css-->
           <link rel="stylesheet" type ="text/css" href="css/1.css">
            </head>
	<body>
    <a href="http:www.baidu.com">百度</a>
	</body>
 </html>

cursor:鼠标样式 hander是小手

## 列表样式

以下面代码为例

<style type="text/css">
ul{
    list-style-type : none;
    }
</style>
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

### 绝对定位

代码如下：↓

<!DOCTYPE html><html>
<head>
<meta charset="utf-8">
<title>css样式的绝对定位</title><style type="text/css">
#div1{
backgroud-color : red;
position :absolute;/*绝对定位*/
    width :300px;
    height : 300px;
    left:100px;
    top:100px;
    }
</style>
</head>
<body>
<div id="div1"></dfv)
</body></html>