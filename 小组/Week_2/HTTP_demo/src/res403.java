import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet("/res403")
public class res403 extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html");
        resp.setStatus(HttpServletResponse.SC_FORBIDDEN);
        int status = resp.getStatus();
        resp.getWriter().println("<h1>响应码:"+ status +"</h1>");
        resp.getWriter().println("禁止访问");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html");
        resp.setStatus(HttpServletResponse.SC_FORBIDDEN);
        int status = resp.getStatus();
        resp.getWriter().println("<h1>响应码:"+ status +"</h1>");
        resp.getWriter().println("禁止访问");
    }
}
