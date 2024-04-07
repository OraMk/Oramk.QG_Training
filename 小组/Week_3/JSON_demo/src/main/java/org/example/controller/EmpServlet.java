package org.example.controller;


import com.fasterxml.jackson.databind.ObjectMapper;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.example.Dao.getData;
import org.example.pojo.User;
import org.example.pojo.emp;

import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

@WebServlet(urlPatterns = "/EmpServlet")
public class EmpServlet extends HttpServlet {
    private List<emp> list = null;
    private org.example.Dao.getData getData = new getData();



    public EmpServlet() throws SQLException, IOException, ClassNotFoundException {

    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        if (list == null)
        {

            list = getData.getAllDate();
        }else{
            list.clear();
            list = getData.getAllDate();

        }
        ObjectMapper mapper = new ObjectMapper();
        mapper.writeValue(resp.getWriter(),list);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }
}
