package com.pojo;

public class emp {

   private int empno;
   private String ename;
   private String job;
   private Integer mgr;
   private String hiredate;
   private double sal;
   private Double comm;
   private int deptno;


   public int getEmpno() {
      return empno;
   }

   public void setEmpno(int empno) {
      this.empno = empno;
   }

   public String getEname() {
      return ename;
   }

   public void setEname(String ename) {
      this.ename = ename;
   }

   public String getJob() {
      return job;
   }

   public void setJob(String job) {
      this.job = job;
   }

   public int getMgr() {
      return mgr;
   }

   public void setMgr(int mgr) {
      this.mgr = mgr;
   }

   public String getHiredate() {
      return hiredate;
   }

   public void setHiredate(String hiredate) {
      this.hiredate = hiredate;
   }

   public double getSal() {
      return sal;
   }

   public void setSal(double sal) {
      this.sal = sal;
   }

   public double getComm() {
      return comm;
   }

   public void setComm(double comm) {
      this.comm = comm;
   }

   public int getDeptno() {
      return deptno;
   }

   public void setDeptno(int deptno) {
      this.deptno = deptno;
   }

   @Override
   public String toString() {
      return "emp{" +
              "empno=" + empno +
              ", ename='" + ename + '\'' +
              ", job='" + job + '\'' +
              ", mgr=" + mgr +
              ", hiredate='" + hiredate + '\'' +
              ", sal=" + sal +
              ", comm=" + comm +
              ", deptno=" + deptno +
              '}';
   }
}
