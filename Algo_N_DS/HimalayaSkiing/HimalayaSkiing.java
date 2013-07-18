package com.himalaya.skiing;

import java.util.Vector;

public class HimalayaSkiing {

	/**
	 * @param args
	 */
	public static final int R = 5;
	public static final int C = 5;
	public static int topCount    = 0;
	public static int leftCount    = 0;
	public static int bottomCount = 0;
	public static int rightCount  = 0;
	public static Vector<Integer> finalList = new Vector<Integer>(); 
	
	enum SIDE{TOP, LEFT, BOTTOM, RIGHT,CENTER};
	
	public static boolean noWay(int[][] A, int i, int j){
		
		if(i == 0 && j == 0 && A[i][j] < A[i][j+1] && A[i][j] < A[i+1][j]){
			return true;
		}
		else if(i == 0 && j == C-1 && A[i][j] < A[i][j-1] && A[i][j] < A[i+1][j]){
			return true;
		}
		else if(i == R-1 && j == 0 && A[i][j] < A[i-1][j] && A[i][j] < A[i][j+1]){
			return true;
		}
		else if(i == R-1 && j == C-1 && A[i][j] < A[i-1][j] && A[i][j] < A[i][j-1]){
			return true;
		}
		else if(i == 0 && j > 0 && j < C-1 && A[i][j] < A[i][j-1] && A[i][j] < A[i+1][j] && A[i][j] < A[i][j+1]){
			return true;
		}
		else if(i == R-1 && j > 0 && j < C-1 && A[i][j] <A[i][j-1] && A[i][j] <  A[i-1][j] && A[i][j] < A[i][j+1]){
			return true;
		}
		else if(i > 0 && i < R-1 && j == 0 && A[i][j] < A[i-1][j] && A[i][j] < A[i][j+1] && A[i][j] < A[i+1][j]){
			return true;
		}
		else if(i > 0 && i < R-1 && j == C-1 && A[i][j] < A[i-1][j] && A[i][j] < A[i][j-1] && A[i][j] < A[i+1][j]){
			return true;
		}
		else if(i > 0 && i < R-1 && j > 0 && j < C-1 && A[i][j] < A[i-1][j] && A[i][j] < A[i][j-1] && A[i][j] < A[i+1][j] && A[i][j] < A[i][j+1]){
			return true;
		}
		return false;
	}
	public static void tracePath(int[][] A, int i, int j, int count, SIDE side)
	{
		if (noWay(A, i,j)){
			System.out.println("Value = " + topCount);
			//topCount = 0;
			//return;
		}
		else
		{
			if(0 < i && A[i][j] > A[i-1][j] && side != SIDE.TOP){
				tracePath(A, i-1, j,topCount++, SIDE.BOTTOM);
			}
			if(0 < j && A[i][j] > A[i][j-1] && side != SIDE.LEFT){
				tracePath(A, i, j-1,topCount++, SIDE.RIGHT);
			}
			if(i+1 < R && A[i][j] > A[i+1][j] && side != SIDE.BOTTOM){
				tracePath(A, i+1, j,topCount++, SIDE.TOP);
			}
			if(j+1 < C && A[i][j] > A[i][j+1] && side != SIDE.RIGHT){
				tracePath(A, i, j+1,topCount++, SIDE.LEFT);
			}
			
		}
		topCount--;
	}
	
	public static void takeBiggest()
	{
		finalList.add(topCount);
		topCount = 0;
		finalList.add(leftCount);
		leftCount = 0;
		finalList.add(bottomCount);
		bottomCount = 0;
		finalList.add(rightCount);
		rightCount = 0;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] hillTops = new int[R][C];
		hillTops[0][0] = 7; hillTops[0][1] = 2;  hillTops[0][2]= 3;  hillTops[0][3] = 4;  hillTops[0][4] = 5;
		hillTops[1][0] = 36;hillTops[1][1] = 37; hillTops[1][2]= 38; hillTops[1][3] = 34; hillTops[1][4] = 6;
		hillTops[2][0]= 33; hillTops[2][1] = 44; hillTops[2][2]= 46; hillTops[2][3] = 40; hillTops[2][4]= 7;
		hillTops[3][0]= 24; hillTops[3][1] = 43; hillTops[3][2]= 42; hillTops[3][3] = 41; hillTops[3][4]= 8;
		hillTops[4][0]= 35; hillTops[4][1] = 32; hillTops[4][2]= 47; hillTops[4][3] = 30; hillTops[4][4]= 9;
		for (int i = 0; i < R; i++){
			for (int j = 0; j < C; j++){
				System.out.println("A[" + i +"]" + "[" + j +"] = " + hillTops[i][j]);
				tracePath(hillTops,i,j, 0, SIDE.CENTER);
				takeBiggest();
			}
		}
		/*for (int x : finalList){
			System.out.println("Value = " + x);
		}*/
	}
	

}
