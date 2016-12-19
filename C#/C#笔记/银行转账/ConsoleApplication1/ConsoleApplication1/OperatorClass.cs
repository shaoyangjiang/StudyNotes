using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
 public  class OperatorClass
    {
     Account[] acc = new Account[3];
     int ArrInt;//数组序号 
     /// <summary>
     /// 初始化数据
     /// </summary>
     public void InitData()
     {
         for (int i = 0; i <acc.Length; i++)
         {
             acc[i] = new Account();
             Console.WriteLine("请输入第{0}个姓名:",i+1);
             acc[i].Name = Console.ReadLine();
             Console.WriteLine("请输入第{0}个账号",i+1);
             acc[i].AccountNo = Console.ReadLine();
             Console.WriteLine("请输入第{0}个身份证号",i+1);
             acc[i].CardNo = Console.ReadLine();
             Console.WriteLine("请输入第{0}个账户余额",i+1);
             acc[i].Balance = int.Parse(Console.ReadLine());
         }
     }
     public void login()
     {
       
         for (int i = 0; i < 3; i++)
         {
             Console.WriteLine("请输入您的账号");
             string account = Console.ReadLine();
             Console.WriteLine("请输入您的身份证号");
             string CardNo = Console.ReadLine();
             bool istrue = false;//判断是否寻找到
             for (int j = 0; j < acc.Length; j++)
             {
                 if (acc[j].CardNo.Equals(CardNo)&&acc[j].AccountNo.Equals(account))
                 {
                     ArrInt = j;
                     istrue = true;
                     break;
                 }
             }
             
             if (!istrue)
             {
                 Console.WriteLine("登陆失败!");
                 continue;
             }
             else
             {
                 return;
             }
         }
         
     }

     /// <summary>
     /// 显示菜单
     /// </summary>
     public void showMenu()
     {
         login();
         string option = "";
         do
         {
             
             Console.WriteLine("==================欢迎使用自动银行服务==================");
             Console.WriteLine("1:存款 2:取款 3:转账 4:查询余额 5:退出");
             Console.WriteLine("========================================================");
             option = Console.ReadLine();
             switch (option)
             {
                 case "1":
                     SaveMoney(acc[ArrInt]);                      
                     continue;
                 case "2":
                     WithDraw(acc[ArrInt]);
                     continue;
                 case "3":
                     chargeAccount(acc[ArrInt]);
                     continue;
                 case "4":
                     showbalance(acc[ArrInt]);
                     continue;
                 case "5":
                     break;      //结束switch
                 default:
                     Console.WriteLine("输入无效！");
                     continue;
             }

             break;              //结束do-while循环
         } while (true);
     }

     private void chargeAccount(Account account)
     {
         Console.WriteLine("请输入您要转入的账户");
         string accountNO = Console.ReadLine();
         
         Console.WriteLine("请输入转入的身份证号");
         string CardNo = Console.ReadLine();
         
         int No=-1;

         for (int j = 0; j < acc.Length; j++)
         {
             if (acc[j].CardNo.Equals(CardNo) && acc[j].AccountNo.Equals(accountNO))
             {
                 No = j;
             }
         }
         if (No==-1)
         {
             Console.WriteLine("此账号不存在");
             return;
         }
         else
         {
             Console.WriteLine("请输入转入的金额");
             acc[No].Balance = acc[No].Balance + Convert.ToInt32(Console.ReadLine());
             acc[ArrInt].Balance = acc[No].Balance - Convert.ToInt32(Console.ReadLine());

         }
     }

     private void showbalance(Account item)
     {
         Console.WriteLine("姓名\t账号\t身份证号\t账户余额");
        
             Console.WriteLine("{0}\t{1}\t{2}\t{3}", item.Name, item.AccountNo, item.CardNo, item.Balance);

       
     }

     private void SaveMoney(Account obj)
     {
         Console.WriteLine("请输入要存款的金额");
         obj.Balance = Convert.ToInt32(Console.ReadLine())+obj.Balance;
         Console.WriteLine("当前余额为:{0}", obj.Balance);
     }
     /// <summary>
     /// 取款
     /// </summary>
     private void WithDraw(Account obj)
     {
         Console.WriteLine("请输入要取款的金额");
         int balance = obj.Balance - Convert.ToInt32(Console.ReadLine());
         if (balance<0)
         {
             Console.WriteLine("当前余额不足");
         }
         else
         {
             obj.Balance=balance;
             Console.WriteLine("当前余额为:{0}", obj.Balance);
         }
    
     }
    

     /// <summary>
     /// 显示数据
     /// </summary>
     public void show()
     {
        
         Console.WriteLine("姓名\t账号\t身份证号\t账户余额");
         foreach (Account item in acc)
         {
             Console.WriteLine("{0}\t{1}\t{2}\t{3}",item.Name,item.AccountNo,item.CardNo,item.Balance);

         }
         
     }

    }
}
