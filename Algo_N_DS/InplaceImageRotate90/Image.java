package com.image;

public class Image {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] Image = new int[4][4];
		
		loadImage(Image,4);
		System.out.println("Before Rotating");
		
		displayImage(Image,4);
		
		rotateRight90(Image,4);
		
		System.out.println();
		System.out.println();
		System.out.println("After Rotating Right");
		displayImage(Image,4);
		
		rotateLeft90(Image,4);
		
		System.out.println();
		System.out.println();
		System.out.println("After Rotating Left");
		displayImage(Image,4);
	}
	
	public static void rotateRight90(int[][] image, int N)
	{
//		int val = 0;
		//int a,b;
		
		for (int i = 0; i < N/2; i++)
		{
			int b = N-(i+1);
			for(int j = i; j < b;j++)
			{
				int offset = j-i;
				int tmp = image[i][j];
				image[i][j] = image[b-offset][i];
				image[b-offset][i] = image[b][b-offset];
				image[b][b-offset] = image[j][b];
				image[j][b] = tmp;
				
			}
		}
	}
	
	public static void rotateLeft90(int[][] image, int N)
	{
//		int val = 0;
		//int a,b;
		
		for (int i = 0; i < N/2; i++)
		{
			int b = N-(i+1);
			for(int j = i; j < b;j++)
			{
				int offset = j-i;
				int tmp = image[i][j];
				image[i][j] = image[j][b];
				image[j][b] = image[b][b-offset];
				image[b][b-offset] = image[b-offset][i];
				image[b-offset][i] = tmp;
			}
		}
	}
	
	public static void displayImage(int[][] image, int N)
	{
		for (int i = 0; i < N; i++)
		{
			System.out.println();
			for (int j = 0; j < N; j++)
			{
				System.out.print(image[i][j] + " ");
			}
		}
	}
	
	public static void loadImage(int[][] image, int N)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				image[i][j] = j;
			}
		}
	}

}
