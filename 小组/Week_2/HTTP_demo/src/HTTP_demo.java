import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;

@WebServlet("/HTTP_demo")
public class HTTP_demo extends HttpServlet {


    public void request(HttpServletRequest req, HttpServletResponse resp , String request) throws IOException {
        //获取前端的请求
        StringBuffer url = req.getRequestURL();
        String method = req.getMethod();
        String parameterNames = req.getQueryString();
        //后台向前端发出响应
        int status = resp.getStatus();
        resp.setContentType("text/html");
        PrintWriter out = resp.getWriter();
        out.print("已发送" + request  + "请求<br>");
        out.print("URL: " +url+"<br>");
        out.print("方法: " +method+"<br>");
        out.print("请求参数: " +parameterNames+"<br>");
        out.print("响应码： "+ status);
    }
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        request(req,resp,"GET");

    }

    @Override
    protected void doHead(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        后台向前端发出响应
        resp.setContentType("text/html");
        PrintWriter out = resp.getWriter();

        out.print("已发送HEAD请求");

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        request(req,resp,"POST");
    }

    @Override
    protected void doPut(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        request(req,resp,"PUT");
    }

    @Override
    protected void doDelete(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        request(req,resp,"DELETE");
    }

    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        request(req,resp,"OPTIONS");
    }

    @Override
    protected void doTrace(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        request(req,resp,"TRACE");
    }
}
