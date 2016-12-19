package com.tiantian.c3p0dbhelper;

import java.beans.PropertyVetoException;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import com.mchange.v2.c3p0.ComboPooledDataSource;

public class C3p0DbHelper {
	private static ComboPooledDataSource cpds = new ComboPooledDataSource();
	static {
		try {
			// ������
			cpds.setDriverClass("com.mysql.jdbc.Driver");
			// ���ݿ�url
			cpds.setJdbcUrl("jdbc:mysql://localhost:3306/hibernate");
			// �û���
			cpds.setUser("root");
			// ����
			cpds.setPassword("sigma");
			// ��ʼ�����ӳصĴ�С
			cpds.setInitialPoolSize(30);
			// ��С������
			cpds.setMinPoolSize(20);
			// ���������
			cpds.setMaxPoolSize(100);
		} catch (PropertyVetoException e) {
			e.printStackTrace();
		}

	}

	/**
	 * �������ݿ������
	 * 
	 * @return ����Connection
	 */
	public static Connection getConnection() {
		try {
			return cpds.getConnection();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}

	/**
	 * ���ڹر����ݿ�Ĺر�
	 * @param rs ResultSet����
	 * @param st Statement����
	 * @param con Connection����
	 */
	public static void closeJDBC(ResultSet rs, Statement st, Connection con) {
		if (rs != null) {
			try {
				rs.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		if (st != null) {
			try {
				st.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		if (con != null) {
			try {
				con.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}

}
