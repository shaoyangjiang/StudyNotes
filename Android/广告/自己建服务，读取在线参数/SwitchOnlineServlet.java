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
 * ����URL
 * http://localhost:8080/SwitchOnline/SwitchOnlineServlet?number=1234
 * @author Administrator
 *
 */
public class SwitchOnlineServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		String number = req.getParameter("number");//�õ�������������number����
		Properties prop = new Properties();//new �������ļ�
		InputStream is = getServletContext().getResourceAsStream(File.separator + "apps_state.properities");
		prop.load(is);
		String result = prop.getProperty(number);//�õ���������Ӧ��ֵ
		resp.setCharacterEncoding("utf-8");
		resp.setContentType("text/html");
		System.out.println(result);
		PrintWriter out = resp.getWriter();//����
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
