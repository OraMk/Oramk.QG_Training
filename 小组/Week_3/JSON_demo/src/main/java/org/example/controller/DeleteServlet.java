package org.example.controller;


import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.example.Dao.getData;

import java.io.IOException;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.Map;

@WebServlet(urlPatterns = "/deleteServlet")
public class DeleteServlet extends HttpServlet {
    private org.example.Dao.getData getData = new getData();



    public DeleteServlet() throws SQLException, IOException, ClassNotFoundException {

    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
       String empno =  req.getParameter("empno");
       getData.Delete(empno);
       resp.sendRedirect("/JSON_demo_war/displayData.html");

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }
}
