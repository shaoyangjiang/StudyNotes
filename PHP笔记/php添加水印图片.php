<?php
 $ori_img = "test.jpg"; //ԭͼ
 $water_img = "logo.jpg"; //ˮӡ
 $new_img = "aa.jpg"; //����ˮӡ���ͼƬ
 
 $original = getimagesize($ori_img); //�õ�ͼƬ����Ϣ������print_r($original)����������һ������
 $watermark = getimagesize($water_img);
 
 $s_original = imgCreateFrom($ori_img, $original[2]); //$original[2]��ͼƬ���ͣ�����1��ʾgif��2��ʾjpg��3��ʾpng
 $s_watermark = imgCreateFrom($water_img, $watermark[2]);
 
 $posX = $original[0] - $watermark[0]-6; //X���꣨���½ǣ�
 $poxY = $original[1] - $watermark[1]-3; //Y���꣨���½ǣ�
 //��ˮӡ
 imagecopy($s_original, $s_watermark, $posX, $poxY, 0, 0, $watermark[0], $watermark[1]);
 //header("Content-type:image/jpeg");
 //imagejpeg($s_original); //����������ͼƬ
 $loop = imagejpeg($s_original, $new_img); //�����µ�ͼƬ(jpg��ʽ)�������imagepng��������png��ʽ
 if($loop){
  echo "ˮӡ��ӳɹ���";
 }
 
 //�����ļ����� ����һ����ͼ��
 function imgCreateFrom($img_src, $val){
  switch($val){
   case 1 : $img = imagecreatefromgif($img_src);
    break;
   case 2 : $img = imagecreatefromjpeg($img_src);
    break;
   case 3 : $img = imagecreatefrompng($img_src);
    break;
  }
  return $img;
 } 
?>



ʵ�ֶ�

<?php
	//��ͼƬ��Ϊ����
	$img = imagecreatefromjpeg("shandian.jpg");
	//ˮӡͼƬ
	$watermark = imagecreatefrompng("watermark.png");
	
	//���ˮӡ
	imagecopy($img,$watermark,700,460,0,0,240,61);
	
	//���ͼ��
	header("Content-type:image/jpeg");
	imagejpeg($img);
	//����ͼ��
	imagedestroy($img);
?>