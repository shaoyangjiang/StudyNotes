package com.shaoyangjiang.servlet;


import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Properties;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * 请求URL
 * http://localhost:8080/SwitchOnline/SwitchOnlineServlet?number=1234
 * @author Administrator
 *
 */
public class SwitchOnlineServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		String number = req.getParameter("number");//得到浏览器里输入的number参数
		Properties prop = new Properties();//new 出配置文件
		InputStream is = getServletContext().getResourceAsStream(File.separator + "apps_state.properities");
		prop.load(is);
		String result = prop.getProperty(number);//得到参数所对应的值
		resp.setCharacterEncoding("utf-8");
		resp.setContentType("text/html");
		System.out.println(result);
		PrintWriter out = resp.getWriter();//发送
		out.write(result);
		out.flush();
		out.close();
		is.close();
		
	}
	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		this.doGet(req, resp);
	}
}
