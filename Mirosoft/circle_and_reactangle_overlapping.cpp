 bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
 int edgeX = (x_center < x1) ? x1 : (x_center > x2) ? x2 : x_center;
        int edgeY = (y_center < y1) ? y1 : (y_center > y2) ? y2 : y_center;
        int distX = x_center - edgeX, distY = y_center - edgeY;
        return distX * distX + distY * distY <= radius * radius;

        // for(int i=x1;i<=x2;i++){
        //     for(int j=y1;j<=y2;j++){
        //         double p=(i-xCenter)*(i-xCenter) + (j-yCenter)*(j-yCenter);
        //         double r=radius*radius;
        //         if(p<=r) return true;
        //     }
        // }
        // return false;
    }