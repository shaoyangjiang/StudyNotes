/**
 * Copyright 2014 Zhenguo Jin
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.ihongqiqu.util;

import java.io.ByteArrayInputStream;
import java.io.File;

import java.io.FileFilter;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.security.MessageDigest;
import java.security.cert.CertificateException;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

import android.app.ActivityManager;
import android.app.ActivityManager.MemoryInfo;
import android.app.ActivityManager.RunningAppProcessInfo;
import android.app.ActivityManager.RunningServiceInfo;
import android.app.ActivityManager.RunningTaskInfo;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.content.pm.Signature;
import android.net.Uri;
import android.text.TextUtils;

import javax.security.auth.x500.X500Principal;

/**
 * APP������
 * APP�����Ϣ�����ࡣ��ȡ�汾��Ϣ
 *
 * @author jingle1267@163.com
 */
public final class AppUtils {

    private static final boolean DEBUG = true;
    private static final String TAG = "AppUtils";

    /**
     * Don't let anyone instantiate this class.
     */
    private AppUtils() {
        throw new Error("Do not need instantiate!");
    }

    /**
     * �õ�����汾��
     *
     * @param context ������
     * @return ��ǰ�汾Code
     */
    public static int getVerCode(Context context) {
        int verCode = -1;
        try {
            String packageName = context.getPackageName();
            verCode = context.getPackageManager().getPackageInfo(packageName, 0).versionCode;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return verCode;
    }

    /**
     * �õ������ʾ�汾��Ϣ
     *
     * @param context ������
     * @return ��ǰ�汾��Ϣ
     */
    public static String getVerName(Context context) {
        String verName = "";
        try {
            String packageName = context.getPackageName();
            verName = context.getPackageManager().getPackageInfo(packageName, 0).versionName;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return verName;
    }

    /**
     * ��װapk
     *
     * @param context ������
     * @param file    APK�ļ�
     */
    public static void installApk(Context context, File file) {
        Intent intent = new Intent();
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        intent.setAction(Intent.ACTION_VIEW);
        intent.setDataAndType(Uri.fromFile(file),
                "application/vnd.android.package-archive");
        context.startActivity(intent);
    }

    /**
     * ��װapk
     *
     * @param context ������
     * @param file    APK�ļ�uri
     */
    public static void installApk(Context context, Uri file) {
        Intent intent = new Intent();
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        intent.setAction(Intent.ACTION_VIEW);
        intent.setDataAndType(file, "application/vnd.android.package-archive");
        context.startActivity(intent);
    }

    /**
     * ж��apk
     *
     * @param context     ������
     * @param packageName ����
     */
    public static void uninstallApk(Context context, String packageName) {
        Intent intent = new Intent(Intent.ACTION_DELETE);
        Uri packageURI = Uri.parse("package:" + packageName);
        intent.setData(packageURI);
        context.startActivity(intent);
    }

    /**
     * �������Ƿ�����
     *
     * @param context   ������
     * @param className ����
     * @return �Ƿ����е�״̬
     */
    public static boolean isServiceRunning(Context context, String className) {
        boolean isRunning = false;
        ActivityManager activityManager = (ActivityManager) context
                .getSystemService(Context.ACTIVITY_SERVICE);
        List<RunningServiceInfo> servicesList = activityManager
                .getRunningServices(Integer.MAX_VALUE);
        for (RunningServiceInfo si : servicesList) {
            if (className.equals(si.service.getClassName())) {
                isRunning = true;
            }
        }
        return isRunning;
    }

    /**
     * ֹͣ���з���
     *
     * @param context   ������
     * @param className ����
     * @return �Ƿ�ִ�гɹ�
     */
    public static boolean stopRunningService(Context context, String className) {
        Intent intent_service = null;
        boolean ret = false;
        try {
            intent_service = new Intent(context, Class.forName(className));
        } catch (Exception e) {
            e.printStackTrace();
        }
        if (intent_service != null) {
            ret = context.stopService(intent_service);
        }
        return ret;
    }

    /**
     * �õ�CPU������
     *
     * @return CPU������
     */
    public static int getNumCores() {
        try {
            File dir = new File("/sys/devices/system/cpu/");
            File[] files = dir.listFiles(new FileFilter() {
                @Override
                public boolean accept(File pathname) {
                    if (Pattern.matches("cpu[0-9]", pathname.getName())) {
                        return true;
                    }
                    return false;
                }
            });
            return files.length;
        } catch (Exception e) {
            return 1;
        }
    }

    /**
     * whether this process is named with processName
     *
     * @param context     ������
     * @param processName ������
     * @return <ul>
     * return whether this process is named with processName
     * <li>if context is null, return false</li>
     * <li>if {@link ActivityManager#getRunningAppProcesses()} is null,
     * return false</li>
     * <li>if one process of
     * {@link ActivityManager#getRunningAppProcesses()} is equal to
     * processName, return true, otherwise return false</li>
     * </ul>
     */
    public static boolean isNamedProcess(Context context, String processName) {
        if (context == null || TextUtils.isEmpty(processName)) {
            return false;
        }

        int pid = android.os.Process.myPid();
        ActivityManager manager = (ActivityManager) context
                .getSystemService(Context.ACTIVITY_SERVICE);
        List<RunningAppProcessInfo> processInfoList = manager
                .getRunningAppProcesses();
        if (processInfoList == null) {
            return true;
        }

        for (RunningAppProcessInfo processInfo : manager
                .getRunningAppProcesses()) {
            if (processInfo.pid == pid
                    && processName.equalsIgnoreCase(processInfo.processName)) {
                return true;
            }
        }
        return false;
    }

    /**
     * whether application is in background
     * <ul>
     * <li>need use permission android.permission.GET_TASKS in Manifest.xml</li>
     * </ul>
     *
     * @param context ������
     * @return if application is in background return true, otherwise return
     * false
     */
    public static boolean isApplicationInBackground(Context context) {
        ActivityManager am = (ActivityManager) context
                .getSystemService(Context.ACTIVITY_SERVICE);
        List<RunningTaskInfo> taskList = am.getRunningTasks(1);
        if (taskList != null && !taskList.isEmpty()) {
            ComponentName topActivity = taskList.get(0).topActivity;
            if (topActivity != null
                    && !topActivity.getPackageName().equals(
                    context.getPackageName())) {
                return true;
            }
        }
        return false;
    }

    /**
     * ��ȡӦ��ǩ��
     *
     * @param context ������
     * @param pkgName ����
     */
    public static String getSign(Context context, String pkgName) {
        try {
            PackageInfo pis = context.getPackageManager().getPackageInfo(
                    pkgName, PackageManager.GET_SIGNATURES);
            return hexdigest(pis.signatures[0].toByteArray());
        } catch (NameNotFoundException e) {
            e.printStackTrace();
            return null;
        }
    }

    /**
     * ��ǩ���ַ���ת������Ҫ��32λǩ��
     *
     * @param paramArrayOfByte ǩ��byte����
     * @return 32λǩ���ַ���
     */
    private static String hexdigest(byte[] paramArrayOfByte) {
        final char[] hexDigits = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97,
                98, 99, 100, 101, 102};
        try {
            MessageDigest localMessageDigest = MessageDigest.getInstance("MD5");
            localMessageDigest.update(paramArrayOfByte);
            byte[] arrayOfByte = localMessageDigest.digest();
            char[] arrayOfChar = new char[32];
            for (int i = 0, j = 0; ; i++, j++) {
                if (i >= 16) {
                    return new String(arrayOfChar);
                }
                int k = arrayOfByte[i];
                arrayOfChar[j] = hexDigits[(0xF & k >>> 4)];
                arrayOfChar[++j] = hexDigits[(k & 0xF)];
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "";
    }

    /**
     * �����̨���������
     *
     * @param context Ӧ�������Ķ���context
     * @return �����������
     */
    public static int gc(Context context) {
        long i = getDeviceUsableMemory(context);
        int count = 0; // ������Ľ�����
        ActivityManager am = (ActivityManager) context
                .getSystemService(Context.ACTIVITY_SERVICE);
        // ��ȡ�������е�service�б�
        List<RunningServiceInfo> serviceList = am.getRunningServices(100);
        if (serviceList != null)
            for (RunningServiceInfo service : serviceList) {
                if (service.pid == android.os.Process.myPid())
                    continue;
                try {
                    android.os.Process.killProcess(service.pid);
                    count++;
                } catch (Exception e) {
                    e.getStackTrace();
                }
            }

        // ��ȡ�������еĽ����б�
        List<RunningAppProcessInfo> processList = am.getRunningAppProcesses();
        if (processList != null)
            for (RunningAppProcessInfo process : processList) {
                // һ����ֵ����RunningAppProcessInfo.IMPORTANCE_SERVICE�Ľ��̶���ʱ��û�û��߿ս�����
                // һ����ֵ����RunningAppProcessInfo.IMPORTANCE_VISIBLE�Ľ��̶��Ƿǿɼ����̣�Ҳ�����ں�̨������
                if (process.importance > RunningAppProcessInfo.IMPORTANCE_VISIBLE) {
                    // pkgList �õ��ý��������еİ���
                    String[] pkgList = process.pkgList;
                    for (String pkgName : pkgList) {
                        if (DEBUG) {
                            LogUtils.d(TAG, "======����ɱ��������" + pkgName);
                        }
                        try {
                            am.killBackgroundProcesses(pkgName);
                            count++;
                        } catch (Exception e) { // ��ֹ���ⷢ��
                            e.getStackTrace();
                        }
                    }
                }
            }
        if (DEBUG) {
            LogUtils.d(TAG, "������" + (getDeviceUsableMemory(context) - i) + "M�ڴ�");
        }
        return count;
    }

    /**
     * ��ȡ�豸�Ŀ����ڴ��С
     *
     * @param context Ӧ�������Ķ���context
     * @return ��ǰ�ڴ��С
     */
    public static int getDeviceUsableMemory(Context context) {
        ActivityManager am = (ActivityManager) context
                .getSystemService(Context.ACTIVITY_SERVICE);
        MemoryInfo mi = new MemoryInfo();
        am.getMemoryInfo(mi);
        // ���ص�ǰϵͳ�Ŀ����ڴ�
        return (int) (mi.availMem / (1024 * 1024));
    }

    /**
     * ��ȡϵͳ�����е�Ӧ��
     *
     * @param context ������
     * @return Ӧ����ϢList
     */
    public static List<PackageInfo> getAllApps(Context context) {

        List<PackageInfo> apps = new ArrayList<PackageInfo>();
        PackageManager pManager = context.getPackageManager();
        List<PackageInfo> paklist = pManager.getInstalledPackages(0);
        for (int i = 0; i < paklist.size(); i++) {
            PackageInfo pak = paklist.get(i);
            if ((pak.applicationInfo.flags & ApplicationInfo.FLAG_SYSTEM) <= 0) {
                // customs applications
                apps.add(pak);
            }
        }
        return apps;
    }

    /**
     * ��ȡ�ֻ�ϵͳSDK�汾
     *
     * @return ��API 17 �򷵻� 17
     */
    public static int getSDKVersion() {
        return android.os.Build.VERSION.SDK_INT;
    }

    /**
     * �Ƿ�Dalvikģʽ
     *
     * @return ���
     */
    public static boolean isDalvik() {
        return "Dalvik".equals(getCurrentRuntimeValue());
    }

    /**
     * �Ƿ�ARTģʽ
     *
     * @return ���
     */
    public static boolean isART() {
        String currentRuntime = getCurrentRuntimeValue();
        return "ART".equals(currentRuntime) || "ART debug build".equals(currentRuntime);
    }

    /**
     * ��ȡ�ֻ���ǰ��Runtime
     *
     * @return ��������¿���ȡֵDalvik, ART, ART debug build;
     */
    public static String getCurrentRuntimeValue() {
        try {
            Class<?> systemProperties = Class.forName("android.os.SystemProperties");
            try {
                Method get = systemProperties.getMethod("get",
                        String.class, String.class);
                if (get == null) {
                    return "WTF?!";
                }
                try {
                    final String value = (String) get.invoke(
                            systemProperties, "persist.sys.dalvik.vm.lib",
                        /* Assuming default is */"Dalvik");
                    if ("libdvm.so".equals(value)) {
                        return "Dalvik";
                    } else if ("libart.so".equals(value)) {
                        return "ART";
                    } else if ("libartd.so".equals(value)) {
                        return "ART debug build";
                    }

                    return value;
                } catch (IllegalAccessException e) {
                    return "IllegalAccessException";
                } catch (IllegalArgumentException e) {
                    return "IllegalArgumentException";
                } catch (InvocationTargetException e) {
                    return "InvocationTargetException";
                }
            } catch (NoSuchMethodException e) {
                return "SystemProperties.get(String key, String def) method is not found";
            }
        } catch (ClassNotFoundException e) {
            return "SystemProperties class is not found";
        }
    }

    private final static X500Principal DEBUG_DN = new X500Principal(
            "CN=Android Debug,O=Android,C=US");

    /**
     * ��⵱ǰӦ���Ƿ���Debug�汾
     *
     * @param ctx
     * @return
     */
    public static boolean isDebuggable(Context ctx) {
        boolean debuggable = false;
        try {
            PackageInfo pinfo = ctx.getPackageManager().getPackageInfo(ctx.getPackageName(), PackageManager.GET_SIGNATURES);
            Signature signatures[] = pinfo.signatures;
            for (int i = 0; i < signatures.length; i++) {
                CertificateFactory cf = CertificateFactory.getInstance("X.509");
                ByteArrayInputStream stream = new ByteArrayInputStream(signatures[i].toByteArray());
                X509Certificate cert = (X509Certificate) cf
                        .generateCertificate(stream);
                debuggable = cert.getSubjectX500Principal().equals(DEBUG_DN);
                if (debuggable)
                    break;
            }

        } catch (NameNotFoundException e) {
        } catch (CertificateException e) {
        }
        return debuggable;
    }

}