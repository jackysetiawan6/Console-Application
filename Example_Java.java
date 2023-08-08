import java.math.*;
import java.security.MessageDigest;
import java.time.*;
import java.util.*;
public class ObjectOriented
{
    public static void main(String[] args)
    {
        prob005();
    }
    public static void prob001()
    {
        Scanner in = new Scanner(System.in);
        String input = in.nextLine();
        LocalTime time = LocalTime.parse(input.substring(0, input.length() - 2));
        int hour = input.charAt(input.length() - 2) == 'P' ? time.getHour() + 12 : time.getHour();
        int minutes = time.getMinute(), seconds = time.getSecond();
        System.out.printf("%02d:%02d:%02d", hour, minutes, seconds);
        in.close();
    }
    public static void prob002()
    {
        Scanner in = new Scanner(System.in);
        String str = new StringBuffer(String.valueOf(in.nextLong())).reverse().toString();
        int[] arr = str.chars().map(c -> c - '0').toArray();
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + (i == arr.length - 1 ? "" : " "));
        in.close();
    }
    public static void prob003()
    {
        Scanner in = new Scanner(System.in);
        int number = in.nextInt();
        double phi = (1 + Math.sqrt(5)) / 2;
        BigInteger result = BigInteger.valueOf(Math.round(Math.pow(phi, number) / Math.sqrt(5)));
        System.out.println(result);
        in.close();
    }
    public static void prob004()
    {
        Scanner reader = new Scanner(System.in);
        LocalDate deadline = LocalDate.parse("2023-01-20");
        LocalDate date = LocalDate.now();
        System.out.println(date.datesUntil(deadline).count());
        String input = reader.nextLine();
        LocalTime time = LocalTime.parse(input);
        while (LocalTime.parse("00:00:00").isBefore(time))
        {
            time = time.minusSeconds(1);
            System.out.println(time);
            try { Thread.sleep(1000); } catch (Exception e) { System.out.println("Error"); }
        }
        reader.close();
    }
    public static void prob005()
    {
        Thread thread = new Thread(new Runnable()
        {
            @Override
            public void run()
            {
                while (true)
                {
                    try { Thread.sleep(100); } catch (Exception e) { }
                    System.out.println("Function A is running");
                }
            }
        });
        thread.start();
        for (int i = 1; i <= 100; i++)
        {
            if (i == 5) thread.interrupt();
            try { Thread.sleep(500); } catch (Exception e) { }
            System.out.println("Function B is running for " + i + " times");
        }
    }
    public static void prob006()
    {
        String str = "Hello World!";
        try
        {
            MessageDigest md = MessageDigest.getInstance("SHA-512");
            md.update(str.getBytes());
            byte[] digest = md.digest();
            StringBuffer sb = new StringBuffer();
            for (byte b : digest) sb.append(String.format("%02x", b & 0xff));
            System.out.println(sb.toString());
        }
        catch (Exception e)
        {
            System.out.println("Error");
        }
    }
    public static void prob007()
    {
        //
    }
}