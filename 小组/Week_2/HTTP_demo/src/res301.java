import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet("/res301")
public class res301 extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String url = "/HTTP_demo";
        resp.setStatus(HttpServletResponse.SC_MOVED_PERMANENTLY);
        // 使用状态码301进行重定向
        req.getRequestDispatcher(url).forward(req,resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String url = "/HTTP_demo";
        resp.setStatus(HttpServletResponse.SC_MOVED_PERMANENTLY);
        // 使用状态码301进行重定向
        req.getRequestDispatcher(url).forward(req,resp);
    }
}
