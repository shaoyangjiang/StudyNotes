package com.sigma.sigmacoupons.operate;
/*
注意添加SD卡权限
      <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE"/>
    <uses-permission android:name="android.permission.MOUNT_UNMOUNT_FILESYSTEMS"/>
*/
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import android.graphics.Bitmap;
import android.os.Environment;
import android.util.Log;

public class FileUtils {
	private String SDPATH;

	public String getSDPATH() {
		return SDPATH;
	}
	public FileUtils() {
		//得到当前外部存储设备的目录
		// /SDCARD
		SDPATH = Environment.getExternalStorageDirectory() + "/";
	}
	/**
	 * 在SD卡上创建文件
	 * 
	 * @throws IOException
	 */
	public File creatSDFile(String fileName) throws IOException {
		File file = new File(SDPATH + fileName);
		file.createNewFile();
		return file;
	}
	
	/**
	 * 在SD卡上创建目录
	 * 
	 * @param dirName
	 */
	public File creatSDDir(String dirName) {
		File dir = new File(SDPATH + dirName);
		dir.mkdirs();
		return dir;
	}

	/**
	 * 判断SD卡上的文件夹是否存在
	 */
	public boolean isFileExist(String fileName){
		File file = new File(SDPATH + fileName);
		return file.exists();
	}
	
	/**
	 * 将一个InputStream里面的数据写入到SD卡中
	 */
	public File write2SDFromInput(String path,String fileName,InputStream input){
		File file = null;
		OutputStream output = null;
		try{
			creatSDDir(path);
			file = creatSDFile(path + fileName);
			output = new FileOutputStream(file);
			byte buffer [] = new byte[4 * 1024];
			int length = 0;
			while((length = input.read(buffer)) != -1){
				output.write(buffer, 0, length);
			}
			output.flush();
		}
		catch(Exception e){
			e.printStackTrace();
		}
		finally{
			try{
				output.close();
			}
			catch(Exception e){
				e.printStackTrace();
			}
		}
		return file;
	}
	
	/**
	 * 把bitmap保存到sd卡上
	 * @author com.tiantian
	 * @param path
	 * @param fileName
	 * @param bm
	 * @return
	 */
	public int saveBitmap2SD(String path,String fileName, Bitmap bm){
		File file = null;
		try {
			creatSDDir(path);
			file = creatSDFile(path + fileName);
		    FileOutputStream out = new FileOutputStream(file.getPath());
		    bm.compress(Bitmap.CompressFormat.JPEG, 90, out);
		    return 0;
		} catch (Exception e) {
		    e.printStackTrace();
		    return 1;
		}
	}
	/**
	 * 获取某个文件夹的大小 ，单位是kb
	 * @author com.tiantian
	 * @param path
	 * @return 返回-1表示这是个文件而不是文件夹
	 */
	public int getFolderSize(String path){
		int fileLength = 0;
		File dir = new File(path);
		if(dir.isDirectory()){
			File[] files = dir.listFiles();
			for(File file : files){
				fileLength += file.length();
			}
		}else{
			return -1;
		}
		return fileLength / 1024;
	}
	/**
	 * 清空指定文件夹
	 * @author com.tiantian
	 * @param path
	 */
	public void deleteFiles(String path){
		File dir = new File(path);
		if(dir.isDirectory()){
			File[] files = dir.listFiles();
			for(File file : files){
				file.delete();
			}
		}
	}

}