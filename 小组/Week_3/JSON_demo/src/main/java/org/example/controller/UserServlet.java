package org.example.controller;


import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.example.pojo.User;

import java.io.IOException;

@WebServlet(urlPatterns = "/userServlet")
public class UserServlet extends HttpServlet {
    User user = null;
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("gbk");
        String username = req.getParameter("username");
        if (user == null || username != null)
        {
            loginusername(req,resp);
        }
        else if (user.getPassword() == null)
        {
            loginpassword(req,resp);
        }

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }

    public void loginusername(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        String username = req.getParameter("username");
        if ("QGStudio".equals(username))
        {
            if (user == null){
                user = new User();
            }
            user.setUsername(username);
            //设置200
            resp.setStatus(HttpServletResponse.SC_OK);
            resp.getWriter().write("用户名合法");
        }else {
            //设置404
            resp.setStatus(HttpServletResponse.SC_NOT_FOUND);



        }

    }
    public void loginpassword(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        String password = req.getParameter("password");
        if ("QGStudio".equals(password))
        {
            user = new User();
            user.setUsername(password);
            //设置200
            resp.setStatus(HttpServletResponse.SC_OK);
            resp.getWriter().write("密码正确");
        }else {
            //设置404
            resp.setStatus(HttpServletResponse.SC_NOT_FOUND);


        }

    }
}
