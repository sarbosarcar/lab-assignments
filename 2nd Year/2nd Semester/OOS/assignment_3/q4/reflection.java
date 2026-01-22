import java.lang.reflect.*;
class Demo {
    private String pvtField = "Private Field";

    public void pubMethod() {
        System.out.println("Public Method Invoked");
    }

    private void pvtMethod() {
        System.out.println("Private Method Invoked");
    }
}

class Main {
    public static void main(String[] args) throws Exception {

        Demo obj = new Demo();
        
        Class<?> class_ = obj.getClass();
        System.out.println("Class Name: " + class_.getName());

        Method[] methods = class_.getMethods();
        System.out.println("Public Methods:");
        for (int i=0; i<methods.length; i++) {
            System.out.println(methods[i].getName());
        }

        Constructor[] constructors = class_.getConstructors();
        System.out.println("Constructors:");
        for (int i=0; i<constructors.length; i++) {
            System.out.println(constructors[i]);
        }

        Method privateMethod = class_.getDeclaredMethod("pvtMethod");
        privateMethod.setAccessible(true); 
        privateMethod.invoke(obj); 

        Field privateField = class_.getDeclaredField("pvtField");
        privateField.setAccessible(true);  
        System.out.println("Private Field Value: " + privateField.get(obj));
    }
}
