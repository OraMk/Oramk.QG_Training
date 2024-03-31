import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet("/res503")
public class res503 extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html");
        resp.setStatus(HttpServletResponse.SC_SERVICE_UNAVAILABLE);
        // 设置状态码为503
        int status = resp.getStatus();
        resp.getWriter().println("<h1>响应码:" + status + "</h1>");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html");
        resp.setStatus(HttpServletResponse.SC_SERVICE_UNAVAILABLE);
        // 设置状态码为503
        int status = resp.getStatus();
        resp.getWriter().println("<h1>响应码:" + status + "</h1>");
    }
}
