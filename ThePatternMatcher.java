class Geeks{
    
    static void follPatt(String s)
    {
       
       int countx=0;
       int county=0;
       int flag=0;
       int ans=0;
     for(int i=0; i<s.length();i++)
     {
         if(s.charAt(i)=='x')
         {
             if(flag==0)
             countx++;
             if(flag==1)
             {
                 flag=0;
                 if(countx!=county)
                 {
                     ans=1;
                     break;
                 }
                 countx=1;
                 county=0;
                 
             }
         }
         else
         {
             if(flag==0)
             {
             county=1;flag=1;
             }
             
             else
             {
                 county++;
             }
            
         }
        
         
     }
     if(countx==county && ans==0)
       System.out.println('1');
      else
      System.out.println('0');
      
    }
}
