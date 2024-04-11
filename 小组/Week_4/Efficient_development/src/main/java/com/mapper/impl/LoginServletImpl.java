package com.mapper.impl;


import com.Dao.Data;

import com.mapper.BaseServlet;
import com.mapper.LoginServlet;
import com.pojo.User;
import com.untils.JDBC;

import jakarta.servlet.annotation.WebServlet;

import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;



import java.io.IOException;
import java.sql.ResultSet;
import java.sql.SQLException;

@WebServlet(urlPatterns = "/loginServlet")
public class LoginServletImpl extends BaseServlet implements LoginServlet {
    Data data = new Data();
    User user = new User();
    JDBC jdbc = new JDBC();
    public LoginServletImpl() throws SQLException, IOException, ClassNotFoundException {
    }

    @Override
    public void selectUser(HttpServletRequest req, HttpServletResponse resp) {
        try {
//            resp.setContentType("application/json");

            ResultSet resulSet = jdbc.UserSelect(req);
            int count = 0;
            if (resulSet.next()){
                count++;
            }
            if (count == 1){
                resp.setStatus(HttpServletResponse.SC_OK);
            }else {
                resp.setStatus(HttpServletResponse.SC_NOT_FOUND);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }


    @Override
    public void add(HttpServletRequest req, HttpServletResponse resp) {
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        String sql = "insert into User values('"+ username + "','" + password + "')";
        int n = 0;
        n = jdbc.Edit(sql);
        if (n == 1)
        {
            resp.setStatus(HttpServletResponse.SC_OK);
        }else {
            resp.setStatus(HttpServletResponse.SC_NOT_FOUND);
        }
    }
}
