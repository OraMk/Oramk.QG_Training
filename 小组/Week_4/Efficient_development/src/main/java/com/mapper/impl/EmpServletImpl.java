package com.mapper.impl;



import com.Dao.Data;
import com.mapper.BaseServlet;
import com.mapper.EmpServlet;
import com.pojo.emp;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.codehaus.jackson.map.ObjectMapper;


import java.io.IOException;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@WebServlet(urlPatterns = "/EmpServlet")
public class EmpServletImpl extends BaseServlet implements EmpServlet {
    private List<emp> list = null;
    private Data data = new Data();
    private Map<String,Object> map = null;


    public EmpServletImpl() throws SQLException, IOException, ClassNotFoundException {

    }

    @Override
    public void selectAll(HttpServletRequest req, HttpServletResponse resp) {
        if (list == null)
        {

            list = data.getAllDate();
        }else{
            list.clear();
            list = data.getAllDate();

        }
        ObjectMapper mapper = new ObjectMapper();
        try {
            mapper.writeValue(resp.getWriter(),list);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void add(HttpServletRequest req, HttpServletResponse resp) {

        map = new HashMap<String,Object>();
        map.put("empno",req.getParameter("empno"));
        map.put("ename",req.getParameter("ename"));
        map.put("job",req.getParameter("job"));
        map.put("hiredate",req.getParameter("hiredate"));
        map.put("sal",req.getParameter("sal"));
        map.put("comm",req.getParameter("comm"));
        map.put("mgr",req.getParameter("mgr"));
        map.put("deptno",req.getParameter("deptno"));
        data.Insert(map);
        resp.setStatus(HttpServletResponse.SC_OK);
        try {
            resp.getWriter().write("1111");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void delete(HttpServletRequest req, HttpServletResponse resp) {
        String empno =  req.getParameter("empno");
        int n = data.Delete(empno);
        if (n == 1)
        {
            resp.setStatus(HttpServletResponse.SC_OK);
            try {
                resp.getWriter().write("1111");
            } catch (IOException e) {
                throw new RuntimeException(e);
            }

        }else{
            resp.setStatus(HttpServletResponse.SC_NOT_FOUND);
        }

    }
}
