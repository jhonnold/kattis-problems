import java.util.*;

class Agglomerator {
  static class Bubble {
    double x, y, vx, vy, r;
    
    double timeToCollide(Bubble other) {
      // http://twobitcoder.blogspot.com/2010/04/circle-collision-detection.html
      double pX = this.x - other.x;
      double pY = this.y - other.y;
      double vX = this.vx - other.vx;
      double vY = this.vy - other.vy;
      double R = this.r + other.r;

      double a = vX * vX + vY * vY;
      double b = 2 * (pX * vX + pY * vY);
      double c = (pX * pX + pY * pY) - R * R;

      if (b * b - 4 * a * c < 0) return -1; // NO COLLSION

      double t0 = (-b - Math.sqrt(b * b - 4 * a * c)) / (2 * a);
      double t1 = (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a);

      return Math.min(t0, t1);
    }

    Bubble agglomerate(Bubble other) {
      double area = Math.pow(this.r, 2) + Math.pow(other.r, 2);

      Bubble bubble = new Bubble();
      bubble.x = this.x * Math.pow(this.r, 2) / area + other.x * Math.pow(other.r, 2) / area;
      bubble.y = this.y * Math.pow(this.r, 2) / area + other.y * Math.pow(other.r, 2) / area;
      bubble.vx = this.vx * Math.pow(this.r, 2) / area + other.vx * Math.pow(other.r, 2) / area;
      bubble.vy = this.vy * Math.pow(this.r, 2) / area + other.vy * Math.pow(other.r, 2) / area;
      bubble.r = Math.sqrt(area);
      return bubble;
    }

    void update(double t) {
      this.x += t * this.vx;
      this.y += t * this.vy;
    }
  }
  
  public static void main(String[] args) {
    List<Bubble> bubbles = new ArrayList<>();

    Scanner sc = new Scanner(System.in);
    int bubbleCount = sc.nextInt();
    for (int i = 0; i < bubbleCount; i++) {
      Bubble bubble = new Bubble();
      bubble.x = sc.nextInt();
      bubble.y = sc.nextInt();
      bubble.vx = sc.nextInt();
      bubble.vy = sc.nextInt();
      bubble.r = sc.nextInt();

      bubbles.add(bubble);
    }

    double t = 0;
    while (bubbles.size() > 1) {
      double minCollideTime = 1000000000;
      Bubble firstB = null, secondB = null;

      // COMPARE ALL BUBBLES TO SEE IF THEY WILL COLLIDE
      // FIND THE NEXT COLLISION AND SETUP
      for (int i = 0; i < bubbles.size() - 1; i++) {
        for (int j = i; j < bubbles.size(); j++) {
          double timeToCollide = bubbles.get(i).timeToCollide(bubbles.get(j));

          if (timeToCollide > 0 && timeToCollide < minCollideTime) {
            firstB = bubbles.get(i);
            secondB = bubbles.get(j);
            minCollideTime = timeToCollide;
          }
        }
      }

      if (minCollideTime < 1000000000) {
        for (Bubble b : bubbles) b.update(minCollideTime);

        Bubble newB = firstB.agglomerate(secondB);
        bubbles.remove(firstB);
        bubbles.remove(secondB);
        bubbles.add(newB);
        t += minCollideTime;
      } else {
        // NO MORE COLLISIONS
        break;
      }
    }

    System.out.printf("%d %.8f\n", bubbles.size(), t);

    sc.close();
  }
}