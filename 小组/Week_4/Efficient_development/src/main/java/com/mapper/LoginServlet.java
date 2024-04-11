package com.mapper;

import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public interface LoginServlet {

//    查找是否存在该用户
    void selectUser(HttpServletRequest req, HttpServletResponse resp);

//    添加用户数据
    void  add(HttpServletRequest req, HttpServletResponse resp);
}
