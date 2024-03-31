import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet("/res401")
public class res401 extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 设置响应状态码为401
        resp.setContentType("text/html");
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        if (username.equals("qgstudio") && password.equals("qgstudio"))
        {
            resp.setStatus(HttpServletResponse.SC_OK);
            int status = resp.getStatus();
            resp.getWriter().println("<h1>响应码:"+ status +"</h1>");
            resp.getWriter().println("用户 " + username + " 已授权");
        }
        else
        {

            resp.setStatus(HttpServletResponse.SC_UNAUTHORIZED);
            int status = resp.getStatus();
            resp.getWriter().println("<h1>响应码:"+ status +"</h1>");
            resp.getWriter().println("用户 " + username + " 未授权");
        }


    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html");
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        if (username.equals("qgstudio") && password.equals("qgstudio"))
        {
            resp.setStatus(HttpServletResponse.SC_OK);
            int status = resp.getStatus();
            resp.getWriter().println("<h1>响应码:"+ status +"</h1>");
            resp.getWriter().println("用户 " + username + " 已授权");
        }
        else
        {

            resp.setStatus(HttpServletResponse.SC_UNAUTHORIZED);
            int status = resp.getStatus();
            resp.getWriter().println("<h1>响应码:"+ status +"</h1>");
            resp.getWriter().println("用户 " + username + " 未授权");
        }

    }
}
