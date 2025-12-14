/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package authoritymodulegui;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AuthorityModuleGUI {

    public static void main(String[] args) {

        // Frame
        JFrame frame = new JFrame("Authority Dashboard - Module 2");
        frame.setSize(900, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());

        // ===== TOP PANEL (Buttons) =====
        JPanel topPanel = new JPanel();

        JButton btnFetch = new JButton("Fetch Incidents");
        JButton btnHigh = new JButton("View High Priority");
        JButton btnUpdate = new JButton("Update Status");

        topPanel.add(btnFetch);
        topPanel.add(btnHigh);
        topPanel.add(btnUpdate);

        frame.add(topPanel, BorderLayout.NORTH);

        // ===== TABLE =====
        String[] columns = {
                "Incident ID",
                "Type",
                "Location",
                "Severity",
                "Citizen Name",
                "Status"
        };

        DefaultTableModel tableModel = new DefaultTableModel(columns, 0);
        JTable table = new JTable(tableModel);

        JScrollPane scrollPane = new JScrollPane(table);
        frame.add(scrollPane, BorderLayout.CENTER);

        // ===== BUTTON ACTIONS =====

        // Fetch Incidents (Dummy Data)
        btnFetch.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                tableModel.setRowCount(0); // clear table

                tableModel.addRow(new Object[]{1, "Fire", "Gulshan", 5, "Ali", "Pending"});
                tableModel.addRow(new Object[]{2, "Accident", "Saddar", 3, "Ahmed", "Pending"});
                tableModel.addRow(new Object[]{3, "Crime", "Defence", 4, "Sara", "InProgress"});
            }
        });

        // View High Priority (Severity >= 4)
        btnHigh.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                tableModel.setRowCount(0);

                tableModel.addRow(new Object[]{1, "Fire", "Gulshan", 5, "Ali", "Pending"});
                tableModel.addRow(new Object[]{3, "Crime", "Defence", 4, "Sara", "InProgress"});
            }
        });

        // Update Status
        btnUpdate.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                int selectedRow = table.getSelectedRow();

                if (selectedRow == -1) {
                    JOptionPane.showMessageDialog(frame,
                            "Please select an incident first!");
                } else {
                    String newStatus = JOptionPane.showInputDialog(
                            frame,
                            "Enter new status (Pending / InProgress / Resolved):"
                    );

                    if (newStatus != null && !newStatus.isEmpty()) {
                        tableModel.setValueAt(newStatus, selectedRow, 5);
                    }
                }
            }
        });

        frame.setVisible(true);
    }
}