package com.Dao;



import com.pojo.emp;
import com.untils.JDBC;
import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Map;


public class Data {
    private JDBC JDBC = new JDBC();
    private Connection connection = null;
    private PreparedStatement preparedStatement = null;
    private ResultSet resultSet = null;
    private static List<emp> list = new ArrayList<emp>();
    private emp EMP;


    public Data() throws SQLException, IOException, ClassNotFoundException {
        connection = JDBC.getConnection();
        preparedStatement = JDBC.getPreparedStatement();
        resultSet = JDBC.getResultSet();
    }
    public List<emp> getAllDate()
    {
        String sql = "select * from emp";
        ResultSetMetaData metaData = null;
        try {
            //注册数据库操作对象
            preparedStatement = connection.prepareStatement(sql);
            //执行sql语句并获取查询结构集
            resultSet = preparedStatement.executeQuery();
            metaData = resultSet.getMetaData();
            int columnCount = metaData.getColumnCount();

            while(resultSet.next())
            {
                EMP = new emp();
                EMP.setEmpno(resultSet.getInt("empno"));
                EMP.setEname(resultSet.getString("ename"));
                EMP.setJob(resultSet.getString("job"));
                EMP.setMgr(resultSet.getInt("mgr"));
                EMP.setHiredate(resultSet.getString("hiredate"));
                EMP.setSal(resultSet.getDouble("sal"));
                EMP.setComm(resultSet.getDouble("comm"));
                EMP.setDeptno(resultSet.getInt("deptno"));
                list.add(EMP);
            }
            return list;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    public List<emp> Insert(Map<String,Object> map)
    {
        EMP = new emp();
        int empno = Integer.parseInt((String) map.get("empno"));
        String ename = (String) map.get("ename");
        String job = (String) map.get("job");
        int mgr = Integer.parseInt((String)map.get("mgr") ) ;
        String hiredate = (String) map.get("hiredate");
        double sal = Double.parseDouble((String) map.get("sal"));
        double comm = Double.parseDouble((String) map.get("comm") );
        int deptno = Integer.parseInt((String) map.get("deptno"));
        JDBC.InputSql("insert into emp(empno,ename,job,mgr,hiredate,sal,comm,deptno) " +
                "values("+ empno + ",\"" + ename + "\",\"" + job + "\"," + mgr + ",\"" + hiredate
                + "\"," + sal + "," + comm + "," + deptno +")");
        EMP.setEmpno(empno);
        EMP.setEname(ename);
        EMP.setJob(job);
        EMP.setMgr(mgr);
        EMP.setHiredate(hiredate);
        EMP.setSal(sal);
        EMP.setComm(comm);
        EMP.setDeptno(deptno);
        list.add(EMP);
        return list;
    }
    public int Delete(String empno)
    {
        int n = JDBC.Edit("delete from emp where empno = " + empno);
//        for (emp emp:list){
//            if (emp.getEmpno() == Integer.parseInt(empno)){
//                list.remove(emp);
//            }
//        }
        Iterator<emp> iterator = list.iterator();
        while (iterator.hasNext()) {
            emp emp = iterator.next();
            if (emp.getEmpno() == Integer.parseInt(empno)) {
                iterator.remove(); // 使用迭代器的remove方法安全地删除元素
            }
        }
        return n;
    }

}
