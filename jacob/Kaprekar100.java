
import java.util.Scanner;

public class Kaprekar100 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c = 0;//contador de número de entradas        
        int cont = 0;//contador de iteraciones hasta llegar a Kaprekar        
        int entr = Integer.parseInt(sc.nextLine());//número de entradas que se introducirán
        int n;//diferencia ente los dos números reordenados
        
        String num;
        int[] nume = new int[4];
        
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

                n = mayor - menor;
                if (n == 0) {//si es repdigit, break y que de 8 (a lo bruto)
                    cont = 8;
                    break;
                }
                for (int i = 0; i < n; i++) {//añado ceros a la izquierda
                    num = String.format("%04d", n);
                }
                //reasigno array con el nuevo número
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

    //métodos ordenacion (son iguales salvo la comparación n[i]<=>n[j], ¿abstraer?)
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
