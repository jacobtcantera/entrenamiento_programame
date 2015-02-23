
import java.util.*;

public class Alicia232 {

    static int[] DIASMES = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String entrada;
        String[] fechas;
        int noCumples;
        int d1, m1, a1, d2, m2, a2;

        while (!"0 0 0 0 0 0".equals(entrada = sc.nextLine())) {
            noCumples = 0;
            fechas = entrada.split(" ");
            d1 = Integer.parseInt(fechas[0]);
            m1 = Integer.parseInt(fechas[1]);
            a1 = Integer.parseInt(fechas[2]);
            d2 = Integer.parseInt(fechas[3]);
            m2 = Integer.parseInt(fechas[4]);
            a2 = Integer.parseInt(fechas[5]);

            for (int i = 0; i < m2; i++) { //calcula días de meses antes del mes actual 
                noCumples += DIASMES[i];
            }
            for (int i = m1 + 1; i <= 12; i++) { //calcula días de meses despues de mes nacimiento
                noCumples += DIASMES[i];
            }

            //calcula 364 noCumpleaños por cada año, y los días hasta acabar mes nacimiento y hasta llegar a fecha actual
            noCumples += (((a2 - 1) - (a1)) * 364) + (DIASMES[m1] - d1) + d2;

            if (m1 == m2) {
                if (d1 < d2) { //Resta un no cumpleaños si ya ha pasado el día del cumple
                    noCumples -= 1;

                } else if (d1 == d2) {
                    noCumples = 0;
                }
            } else if (m1 < m2) {//Resta un no cumpleaños si ya ha pasado el mes del cumple
                noCumples -= 1;
            }
            System.out.println(noCumples);
        }
    }
}
