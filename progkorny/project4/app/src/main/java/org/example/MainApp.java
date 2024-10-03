package org.example;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class MainApp extends Application {
    private Integer count = 0;

    @Override
    public void start(Stage stage) {
        Label label = new Label(count.toString());
        Button button = new Button("Increment");
        VBox root = new VBox(10, label, button);
        Scene scene = new Scene(root, 400, 200);

        button.setOnAction(event -> {
            count++;
            label.setText(count.toString());
        });
        root.setAlignment(Pos.CENTER);

        stage.setTitle("JavaFX Application");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
