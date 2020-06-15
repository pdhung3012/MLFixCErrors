package fileHandling;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.FileWriter;
import java.io.IOException;

public class FileCleaningForASTParsing {
	public static void main(String [] args) throws IOException, FileNotFoundException{
		for(int i = 1; i < 277; i++) {
			if(i != 139) {
				String nameC = "unitialized" + i +".c";
				String nameTxt = "unitialized" + i +".txt";
				String nameProcessed = "preprocessed-unitialized" + i +".txt";
				changeFileExtension(new File(nameC));
				fileHandling(nameTxt, nameProcessed);
				cleanFile(nameProcessed); //can be commented out if necessary (only call this function if the fileHandling() function adds extra spaces between characters)
			}
		}
	}
	
	/**
	 * Read in a code file in c (but in .txt format) and deletes undesired lines (comments, #include) and writes information to a .txt file
	 * @param filename
	 * @throws IOException, FileNotFoundException 
	 */
	
	public static void fileHandling(String inputFilename, String outputFilename) throws IOException, FileNotFoundException {
		File f = new File(inputFilename); //create file object
		Scanner sc = new Scanner(f); //create scanner object to read file contents
		//Read in line by line of the file
		//If the first character of the string of the line is # or /, don't include in the translated .txt file
		//If the line is not undesired (explained above), add it to the .txt file
		//Also, if the line contains \n inside of quotations, remove the \n but keep rest of line
		String writeToFile = "";
		while(sc.hasNextLine()) {
			String line = sc.nextLine();
			if(hasDirectiveOrDefine(line)) {
				//line is undesired and should not be added to file
				writeToFile += "\n"; //add empty line so that the labels we made for the unitialized variables location is still valid
				continue;
			}
			if(hasComment(line)) {
				line = removeComment(line);
			}
			//otherwise, add it to file after removing a possible "\n"
			line = removeEndOfLineInsideQuotations(line);
			writeToFile += line + "\n";
		}
		//close input file
		sc.close();
		//open output file
		FileWriter fileOut = new FileWriter(outputFilename);
		fileOut.write(writeToFile);
		fileOut.close();
	}
	
	private static boolean hasComment(String line) {
		for(int i = 0; i < line.length() - 2; i++) {
			char c = line.charAt(i);
			char cNext = line.charAt(i+1);
			char cNextNext = line.charAt(i+2);
			if(c=='/' && (cNext == '/' || cNextNext == '/')){
				return true;
			}
		}
		return false;
	}
	
	private static boolean hasDirectiveOrDefine(String line) {
		for(int i = 0; i < line.length() - 1; i++) {
			char c = line.charAt(i);
			if(c=='#'){
				return true;
			}
		}
		return false;
	}
	
	private static String removeEndOfLineInsideQuotations(String line) {
		for(int i = 0; i < line.length()-2; i++) {
			char c = line.charAt(i);
			if(c=='"') {
				int j = i;
				while(j < line.length()-2) {
					c = line.charAt(j);
					char cNext = line.charAt(j+1);
					char cNextNext = line.charAt(j+2);
					if((c == '\\' && cNext == 'n') || c=='\n' || (c == '\\' && cNextNext == 'n')){
						String out =line.substring(0, j) + line.substring(j+2, line.length());
						return out;
					}
					j++;
				}
			}
		}
		return line;
	}
	
	public static String removeComment(String line) {
		for(int i = 0; i < line.length(); i++) {
			char c = line.charAt(i);
			if(c=='/') {
				return line.substring(0, i);
			}
		}
		return line;
	}
	
	//changes .c to .txt file formats
	public static void changeFileExtension(File file) {
		file.renameTo(new File(file.getName().substring(0, file.getName().length()-2) + ".txt"));
	}
	
	public static String cleanLine(String line) {
		if(line.length()>=1) {
			line = line.substring(1);
			for(int i = 1; i < line.length(); i++) {
				line = line.substring(0, i) + line.substring(i+1, line.length());
			}
		}
		return line;
	}
	
	//in some cases, the file handling function added extra spaces between all the characters
	//this function removes those extra spaces
	public static void cleanFile(String filename) throws IOException {
		File f = new File(filename);
		Scanner sc = new Scanner(f);
		String writeToFile = "";
		while(sc.hasNextLine()) {
			String line = sc.nextLine();
			writeToFile += cleanLine(line) + "\n";
		}
		sc.close();
		FileWriter fileOut = new FileWriter(filename);
		fileOut.write(writeToFile);
		fileOut.close();
	}
}
