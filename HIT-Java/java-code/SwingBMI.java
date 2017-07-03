package edu.hit1162800204.experiment7;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;





public class SwingBMI extends JFrame  {
	private static final long serialVersionUID = 1L;
	static List<Student> students=new ArrayList<Student>();
	public SwingBMI(){}

	public static void main(String[] agrv){
		SwingBMI stu=new SwingBMI();	
		final JFrame frame = new JFrame("CMS");	
		JMenuBar menu = new JMenuBar();

		JMenu opMenu = new JMenu("Operations");
		JMenuItem listitem = new JMenuItem("List students");
		listitem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				stu.showStudetns(frame);
				
			}
		});
		opMenu.add(listitem);
		menu.add(opMenu);
		frame.setJMenuBar(menu);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setBounds(5, 5, 500, 300);
		frame.setVisible(true);
		
		//frame.setResizable(false);

	}
	
	private void showStudetns(JFrame frame ){
		new resultPanel(frame);
		setVisible(true);
	}

	public static void menu(Scanner in){

		System.out.printf("do you want:\n"
				+ "1���ѧ����Ϣ���ɼ��ļ����棻\n"
				+ "2ѧ����ѯ�����ӡ�ɾ�����޸�\n"
				+ "3���㲢��ʾͳ�ƽ��\n"
				+ "4��ȡѧ����Ϣ\n");
		switch(in.nextInt()){
		case 1:	String str;
			do{	
				System.out.println("please input the ID");
				genStudents(in.next());
				System.out.println("Do you want to creat next random student?");
				str=in.next();
			}while(str.compareTo("Y")==0||str.compareTo("y")==0);
			break;
		case 2:findStudent(students,in);	
			break;
		case 3:
			double aver=AverofBMI(),mod=ModofBMI(),med=MedianofBMI(),var=VarianceofBMI();
			System.out.printf("\nsort by bmi\n");
			printStatics(aver,mod,med,var);
			break;
		default:readFile("student.txt");break;
		}saveFile(students, "student.txt");
	}

	public static void saveFile(List<Student> students2, String filename){
		File file = new File("."+File.separator+filename);
	    if(!file.exists()) { 
	    	 try {
		            file.createNewFile(); 
		            System.out.println(file.getName() + " �����ɹ�");
		        } catch (IOException e) {
		            e.printStackTrace();
		        }
	    }
	    FileWriter writer;
    	try {
    	      writer = new FileWriter(filename, false);
    	      writer.write(String.format("ID\tNAME\tHEIGHT\tWEIGHT\tBMI\r\n"));
              for(Student st: students2){
            	  writer.write(String.format("%s\t%s\t%.2f\t%.2f\t%.2f\r\n", 
            			  st.number,st.name,st.height,st.weight,st.bmi));
              }
              writer.close();
    	} catch (IOException e) {
    		e.printStackTrace();
    	}
    	System.out.println("SAVE SUCCESS!");
	}
	
	public static  ArrayList<Student>  readFile(String filename){
		ArrayList<Student> buff=new ArrayList<Student>();	
		File file = new File("."+File.separator+filename);
	    if(file.exists()) { 
	        try {
				BufferedReader reader =new BufferedReader(new FileReader(file));
	            String tempString = null;
	            tempString = reader.readLine();
	            while ((tempString = reader.readLine()) != null) {
	                String[] a= tempString.split("\t");
	                Student st= new SwingBMI().new Student(a[0],a[1],
	                		Double.parseDouble(a[2]),Double.parseDouble(a[3]));
	                buff.add(st);
	            }
	            reader.close();
	            System.out.println("READ SUCCESS!");
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			} catch (NumberFormatException e) {
				e.printStackTrace();
			} catch (IOException e) {
				
				e.printStackTrace();
			}
	    } else {
	        System.out.println("the file have noe been found!!");
	    }    
	    return buff;
	}
	
	public ArrayList<Student> genTestStudents() {
		ArrayList<Student> students=new ArrayList<Student>();
		Random ron=new Random();
		char Char[]={
				'A','B','C','D','E','F','G',
				'H','I','J','K','L','M','N',
				'O','P','Q','R','S','T',
				'U','V','W','X','Y','Z',
				'a','b','c','d','e','f','g',
				'h','i','j','k','l','m','n',
				'o','p','q','r','s','t',
				'u','v','w','x','y','z'};
		for(int i=0;i<20;i++){
			String id=String.valueOf(ron.nextInt(100)+100);
			if(isExists(id)){
				i--;
				continue;
			}
			String name="";
			for(int j=0;j<5;j++){name+=Char[ron.nextInt(46)];}
			double height=ron.nextDouble()+1;
			double weight=ron.nextDouble()*60+40;
			students.add(new SwingBMI().new Student(id,name,height,weight));
		}
		System.out.println("Success!");
		return students;
	}
	
	public static void genStudents(String id){
		
		Random ron=new Random();
		char Char[]={
				'A','B','C','D','E','F','G',
				'H','I','J','K','L','M','N',
				'O','P','Q','R','S','T',
				'U','V','W','X','Y','Z',
				'a','b','c','d','e','f','g',
				'h','i','j','k','l','m','n',
				'o','p','q','r','s','t',
				'u','v','w','x','y','z'};
		
			if(isExists(id))return;
			String name="";
			for(int j=0;j<5;j++){name+=Char[ron.nextInt(46)];}
			double height=ron.nextDouble()+1;
			double weight=ron.nextDouble()*60+40;
			students.add(new SwingBMI().new Student(id,name,height,weight));
		
		System.out.println("Success!");
	}
	
	public static Student inputStudent(Scanner in){
		
		System.out.println("please input the ID,name,height and weight:");
		
		String number=in.next();
		String name=in.next();
		double height=in.nextDouble();
		double weight=in.nextDouble();
		Student student=new SwingBMI().new Student(number,name,height,weight);

		return student;
	}
	
	public static boolean isExists(String id){
		for(Iterator<Student> iter = students.iterator();iter.hasNext();){
			Student temp=iter.next();
			if(id.compareTo(temp.number)==0)return true;
		}
		return false;
	}
	
	public static double AverofBMI(){
		double sum=0;
		for(Iterator<Student> iter = students.iterator();iter.hasNext();)
			sum+=iter.next().bmi;
		
		return sum/students.size();
	}
	
	public static double ModofBMI(){
		
		int hash[]=new int[10000];
		for(Iterator<Student> iter = students.iterator();iter.hasNext();)
			hash[(int)iter.next().bmi*100-1]++;
		int max=0;
		for(int i=1;i<hash.length;i++){
			if(hash[i]>hash[max])max=i;
		}
		return max/100.0;
	}	
	
	public static double MedianofBMI(){
		comparator.SortbyBMI();
		if(students.size()%2==0)
			return students.get(students.size()/2).bmi+students.get(students.size()/2-1).bmi;
		
		return students.get(students.size()/2).bmi;
	}	
	
	public static void findStudent(List<Student> stu,Scanner in){
		System.out.println("please input the id:");
		String id=in.next();
		
		for(int i=0;i<students.size();i++){
			
			if(id.compareTo(students.get(i).number)==0){
				System.out.printf("The ID has been found,do you want:\n"
						+ "1 modify\n"
						+ "2 delete\n");
				switch(in.nextInt()){
				case 1:students.set(i,inputStudent(in));break;
				case 2:students.remove(i);break;
				default:System.out.println("ERROR CHIOSE");break;
				}
				return;
			}
		}
		System.out.printf("The ID has not been found,do you want creat?input 1 to do it\n");
		if(in.nextInt()==1)stu.add(inputStudent(in));
	}
	
	public static double VarianceofBMI(){
		double sum=0;
		double aver=AverofBMI();
		for(Iterator<Student> iter = students.iterator();iter.hasNext();){
			Student temp=iter.next();
			sum+=(temp.bmi-aver)*(temp.bmi-aver);
		}
			
		
		return sum/students.size();
	}
	
	public static void printStatics(double aver,double mod,double median,double variance){
		
		System.out.printf("Average is:%.2f\tMode is:%.2f\tMedian is:%.2f\tVariance is:%.2f\n"
				,aver,mod,median,variance);
		System.out.printf("ID\tNAME\tHeight\tWeight\tBMI\n");
		for(Iterator<Student> iter = students.iterator();iter.hasNext();){
			Student temp=iter.next();
			System.out.printf("%s\t%s\t%.2f\t%.2f\t%.2f\n",
					temp.number,temp.name,
					temp.height,temp.weight,temp.bmi);
		}
	}
	
	public static class comparator{
		
		public static void SortbyBMI(){
			for(int i=0;i<students.size();i++){
				int min=i;
				for(int j=i+1;j<students.size();j++){
					if(students.get(j).bmi<students.get(min).bmi)min=j;
				}
				if(min!=i){
					Student temp=students.get(i);
					students.set(i, students.get(min));
					students.set(min,temp);
				}
			}
		}
		
		public static void SortbyID(){
			for(int i=0;i<students.size();i++){
				int min=i;
				for(int j=i+1;j<students.size();j++){
					if(students.get(j).number.compareTo(students.get(min).number)<0)min=j;
				}
				if(min!=i){
					Student temp=students.get(i);
					students.set(i, students.get(min));
					students.set(min,temp);
				}
			}
		}
		
		public static void SortbyNAME(){
			for(int i=0;i<students.size();i++){
				int min=i;
				for(int j=i+1;j<students.size();j++){
					if(students.get(j).name.compareTo(students.get(min).name)<0)min=j;
				}
				if(min!=i){
					Student temp=students.get(i);
					students.set(i, students.get(min));
					students.set(min,temp);
				}
			}
		}
		
		
		public static void SortbyHeight(){
			for(int i=0;i<students.size();i++){
				int min=i;
				for(int j=i+1;j<students.size();j++){
					if(students.get(j).height<students.get(min).height)min=j;
				}
				if(min!=i){
					Student temp=students.get(i);
					students.set(i, students.get(min));
					students.set(min,temp);
				}
			}
		}
		
		public static void SortbyWeight(){
			for(int i=0;i<students.size();i++){
				int min=i;
				for(int j=i+1;j<students.size();j++){
					if(students.get(j).weight<students.get(min).weight)min=j;
				}
				if(min!=i){
					Student temp=students.get(i);
					students.set(i, students.get(min));
					students.set(min,temp);
				}
			}
		}
	}

	public class Student{
	
		String number="",name="";
		double height=0.0,weight=0.0,bmi=0.0;
		
		public Student(){}
		public Student(String number,String name,double height,double weight){
			this.number=number;
			this.name=name;
			this.height=(int)(height*100)/100.0;
			this.weight=(int)(weight*100)/100.0;
			this.bmi=(int)(weight/(height*height))*100/100.0;
		}
		
	}
	
	class resultPanel extends JPanel{

		private static final long serialVersionUID = 1L;

		public resultPanel(JFrame frame) {
			JTextArea ta= new JTextArea("",20,40);
			ArrayList<Student> alst= genTestStudents();
			StringBuffer sb = new StringBuffer();
			sb.append("ID\tName\tWeight\tHeight\tBMI").append("\n");
			for(Student st: alst){
				sb.append(String.format("%s\t%s\t%.2f\t%.2f\t%.2f\r\n", 
          			  st.number,st.name,st.height,st.weight,st.bmi));
			}
			ta.setText(sb.toString());
			ta.setEditable(false);		
			frame.add(new JScrollPane(ta));
		}
	}



}