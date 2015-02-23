
import java.util.Scanner;

public class Kaprekar100 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c = 0;
        int entr = Integer.parseInt(sc.nextLine());
        int l;
        int[] may, men;
        String num;
        String[] n;
        int[] nume = new int[4];
        int cont = 0;
        while (c < entr) {

            num = sc.nextLine();
            for (int i = 0; i < nume.length; i++) {
                nume[i] = Integer.parseInt(num.substring(i, i + 1));
            }

            while (!"6174".equals(num)) {

                ordenaMayAMen(nume);
                int mayor = Integer.parseInt(nume[0] + "" + nume[1] + "" + nume[2] + "" + nume[3]);
                ordenaMenAMay(ordenaMayAMen(nume));
                int menor = Integer.parseInt(nume[0] + "" + nume[1] + "" + nume[2] + "" + nume[3]);

                l = mayor - menor;
                if (l == 0) {
                    cont = 8;
                    break;
                }

                for (int i = 0; i < l; i++) {//añado ceros a la izquierda
                    num = String.format("%04d", l);
                }
            
                nume[0] = Integer.parseInt(num.substring(0, 1));
                nume[1] = Integer.parseInt(num.substring(1, 2));
                nume[2] = Integer.parseInt(num.substring(2, 3));
                nume[3] = Integer.parseInt(num.substring(3, 4));

                cont++;
            }
            c++;
            System.out.println(cont);
            cont = 0;
        }
    }

    static int[] ordenaMayAMen(int[] n) {
        int aux;
        for (int i = 0; i < n.length; i++) {
            for (int j = i; j < n.length; j++) {
                if (n[i] < n[j]) {
                    aux = n[i];
                    n[i] = n[j];
                    n[j] = aux;
                }
            }
        }
        return n;
    }

    static int[] ordenaMenAMay(int[] n) {
        int aux;
        for (int i = 0; i < n.length; i++) {
            for (int j = i; j < n.length; j++) {
                if (n[i] > n[j]) {
                    aux = n[i];
                    n[i] = n[j];
                    n[j] = aux;
                }
            }
        }
        return n;
    }

}
