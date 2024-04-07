package org.example.controller;


import com.fasterxml.jackson.databind.ObjectMapper;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.example.Dao.getData;
import org.example.pojo.emp;

import java.io.IOException;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@WebServlet(urlPatterns = "/InsertServlet")
public class InsertServlet extends HttpServlet {
    private Map<String,Object> map = null;
    private org.example.Dao.getData getData = new getData();



    public InsertServlet() throws SQLException, IOException, ClassNotFoundException {

    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
       map = new HashMap<String,Object>();
       map.put("empno",req.getParameter("empno"));
       map.put("ename",req.getParameter("ename"));
       map.put("job",req.getParameter("job"));
       map.put("hiredate",req.getParameter("hiredate"));
       map.put("sal",req.getParameter("sal"));
       map.put("comm",req.getParameter("comm"));
       map.put("mgr",req.getParameter("mgr"));
       map.put("deptno",req.getParameter("deptno"));
       getData.Insert(map);
       resp.sendRedirect("/JSON_demo_war/displayData.html");

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }
}
