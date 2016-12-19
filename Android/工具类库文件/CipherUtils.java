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

import java.io.UnsupportedEncodingException;
import java.security.Key;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import javax.crypto.Cipher;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.DESKeySpec;

/**
 * ��������ܵĹ�����
 *
 * @author jingle1267@163.com
 */
public final class CipherUtils {

    /**
     * MD5����
     * <br>http://stackoverflow.com/questions/1057041/difference-between-java-and-php5-md5-hash
     * <br>http://code.google.com/p/roboguice/issues/detail?id=89
     *
     * @param string Դ�ַ���
     * @return ���ܺ���ַ���
     */
    public static String md5(String string) {
        byte[] hash = null;
        try {
            hash = MessageDigest.getInstance("MD5").digest(
                    string.getBytes("UTF-8"));
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }

        StringBuilder hex = new StringBuilder(hash.length * 2);
        for (byte b : hash) {
            if ((b & 0xFF) < 0x10)
                hex.append("0");
            hex.append(Integer.toHexString(b & 0xFF));
        }
        return hex.toString();
    }

    /**
     * ���ؿ����㷨DES����Կ
     *
     * @param key ǰ8�ֽڽ�������������Կ��
     * @return ���ɵ���Կ
     * @throws Exception
     */
    public static Key getDESKey(byte[] key) throws Exception {
        DESKeySpec des = new DESKeySpec(key);
        SecretKeyFactory keyFactory = SecretKeyFactory.getInstance("DES");
        return keyFactory.generateSecret(des);
    }

    /**
     * ����ָ������Կ���㷨�����ַ������н��ܡ�
     *
     * @param data      Ҫ���н��ܵ����ݣ�������ԭ����byte[]����ת��Ϊ�ַ����Ľ����
     * @param key       ��Կ��
     * @param algorithm �㷨��
     * @return ���ܺ�Ľ�������ɽ��ܺ��byte[]���´���ΪString�����������ʧ�ܣ�������null��
     * @throws Exception
     */
    public static String decrypt(String data, Key key, String algorithm)
            throws Exception {
        Cipher cipher = Cipher.getInstance(algorithm);
        cipher.init(Cipher.DECRYPT_MODE, key);
        String result = new String(cipher.doFinal(StringUtils
                .hexStringToByteArray(data)), "utf8");
        return result;
    }

    /**
     * ����ָ������Կ���㷨��ָ���ַ������п�����ܡ�
     *
     * @param data      Ҫ���м��ܵ��ַ�����
     * @param key       ��Կ��
     * @param algorithm �㷨��
     * @return ���ܺ�Ľ������byte[]����ת��Ϊ16���Ʊ�ʾ�����顣������ܹ���ʧ�ܣ�������null��
     */
    public static String encrypt(String data, Key key, String algorithm)
            throws Exception {
        Cipher cipher = Cipher.getInstance(algorithm);
        cipher.init(Cipher.ENCRYPT_MODE, key);
        return StringUtils.byteArrayToHexString(cipher.doFinal(data
                .getBytes("utf8")));
    }
}