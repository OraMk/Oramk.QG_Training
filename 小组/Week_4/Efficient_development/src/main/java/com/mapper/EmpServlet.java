package com.mapper;

import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

public interface EmpServlet {
    void selectAll(HttpServletRequest req, HttpServletResponse resp);

    void  add(HttpServletRequest req, HttpServletResponse resp);

    void delete(HttpServletRequest req, HttpServletResponse resp);

}
