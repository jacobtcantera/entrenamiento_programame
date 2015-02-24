
import java.util.Scanner;

public class PenyaAtletica {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numDatos = sc.nextInt();
        sc.nextLine();
        int c = 0, cNum = 0;
        int adm;
        String[] nums;
        int[] arr;
        while (c < numDatos) {
            adm = sc.nextInt();
            sc.nextLine();
            nums = sc.nextLine().split(" ");
            arr = new int[nums.length];
            int i = 0;
            for (String n : nums) {
                arr[i] = Integer.parseInt(n);
                if (arr[i] % 2 == 0) {
                    cNum++;
                }
                i++;
            }
            System.out.println(cNum);
            cNum = 0;
            c++;
        }
    }
}
