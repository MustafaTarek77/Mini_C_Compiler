import tkinter as tk
from tkinter import ttk, scrolledtext, filedialog, messagebox
import subprocess
import os
import threading

class CompilerGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Compiler")
        self.root.geometry("1200x800")
        
        # Create main frame
        main_frame = ttk.Frame(root)
        main_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)
        
        # Toolbar
        toolbar = ttk.Frame(main_frame)
        toolbar.pack(fill=tk.X, pady=(0, 5))
        ttk.Button(toolbar, text="New", command=self.new_file).pack(side=tk.LEFT, padx=2)
        ttk.Button(toolbar, text="Open", command=self.open_file).pack(side=tk.LEFT, padx=2)
        ttk.Button(toolbar, text="Save As", command=self.save_as).pack(side=tk.LEFT, padx=2)
        compile_button = tk.Button(toolbar, text="Compile", command=self.compile_code, 
                                  bg="green", fg="white", activebackground="dark green", 
                                  activeforeground="white")
        compile_button.pack(side=tk.LEFT, padx=2)

        # Paned window for code and output
        paned = ttk.PanedWindow(main_frame, orient=tk.VERTICAL)
        paned.pack(fill=tk.BOTH, expand=True)
        
        # Frame for code editor with line numbers
        editor_frame = ttk.Frame(paned)
        paned.add(editor_frame, weight=70)
        self.line_numbers = tk.Text(editor_frame, width=4, padx=3, takefocus=0,
                                   border=0, background='#f0f0f0', state='disabled')
        self.line_numbers.pack(side=tk.LEFT, fill=tk.Y)
        self.code_editor = scrolledtext.ScrolledText(editor_frame, wrap=tk.NONE, undo=True)
        self.code_editor.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        self.code_editor.bind('<KeyRelease>', self.update_line_numbers)
        self.code_editor.bind('<MouseWheel>', self.update_line_numbers)

        # One output area below
        output_frame = ttk.Frame(paned)
        paned.add(output_frame, weight=30)
        self.error_output = scrolledtext.ScrolledText(output_frame, wrap=tk.WORD, height=10)
        self.error_output.pack(fill=tk.BOTH, expand=True)
        self.error_output.config(state=tk.DISABLED)

        # Status bar
        self.status_var = tk.StringVar()
        self.status_var.set("Ready")
        status_bar = ttk.Label(main_frame, textvariable=self.status_var, relief=tk.SUNKEN, anchor=tk.W)
        status_bar.pack(side=tk.BOTTOM, fill=tk.X)
        self.current_file = None
        self.update_line_numbers()
    
    def update_line_numbers(self, event=None):
        self.line_numbers.config(state=tk.NORMAL)
        self.line_numbers.delete('1.0', tk.END)
        line_count = self.code_editor.get('1.0', tk.END).count('\n')
        for line_num in range(1, line_count + 1):
            self.line_numbers.insert(tk.END, f"{line_num}\n")
        self.line_numbers.config(state=tk.DISABLED)
        self.line_numbers.yview_moveto(self.code_editor.yview()[0])
    
    def new_file(self):
        if messagebox.askyesno("New File", "Do you want to create a new file? Unsaved changes will be lost."):
            self.code_editor.delete(1.0, tk.END)
            self.current_file = None
            self.status_var.set("New file created")
            self.update_line_numbers()
    
    def open_file(self):
        file_path = filedialog.askopenfilename(
            filetypes=[("Text files", "*.txt"), ("C files", "*.c"), ("All files", "*.*")]
        )
        if file_path:
            try:
                with open(file_path, 'r') as file:
                    self.code_editor.delete(1.0, tk.END)
                    self.code_editor.insert(1.0, file.read())
                self.current_file = file_path
                self.status_var.set(f"Opened: {file_path}")
                self.update_line_numbers()
            except Exception as e:
                messagebox.showerror("Error", f"Failed to open file: {e}")
    
    def save_as(self):
        file_path = filedialog.asksaveasfilename(
            defaultextension=".txt",
            filetypes=[("Text files", "*.txt"), ("C files", "*.c"), ("All files", "*.*")]
        )
        if file_path:
            try:
                with open(file_path, 'w') as file:
                    file.write(self.code_editor.get(1.0, tk.END))
                self.current_file = file_path
                self.status_var.set(f"Saved: {file_path}")
            except Exception as e:
                messagebox.showerror("Error", f"Failed to save file: {e}")
    
    def compile_code(self):
        try:
            with open("code.txt", 'w') as file:
                file.write(self.code_editor.get(1.0, tk.END))
            self.status_var.set("Compiling...")
            threading.Thread(target=self._run_compilation).start()
        except Exception as e:
            messagebox.showerror("Error", f"Failed to compile: {e}")
    
    def _run_compilation(self):
        try:
            self.root.after(0, self._clear_output)
            process = subprocess.Popen(['bash', 'build.sh'], 
                                      stdout=subprocess.PIPE, 
                                      stderr=subprocess.PIPE,
                                      text=True)
            stdout, stderr = process.communicate()
            self.root.after(0, lambda: self._check_compilation_results())
        except Exception as e:
            self.root.after(0, lambda: messagebox.showerror("Error", f"Compilation error: {e}"))
    
    def _clear_output(self):
        self.error_output.config(state=tk.NORMAL)
        self.error_output.delete(1.0, tk.END)
        self.error_output.config(state=tk.DISABLED)
    
    def _update_error_output(self, text, tag=None):
        self.error_output.config(state=tk.NORMAL)
        if tag:
            self.error_output.insert(tk.END, text, tag)
        else:
            self.error_output.insert(tk.END, text)
        self.error_output.see(tk.END)
        self.error_output.config(state=tk.DISABLED)
    
    def _update_status(self, text):
        self.status_var.set(text)
    
    def _check_compilation_results(self):
        
        self.error_output.tag_configure("error", foreground="red")
        self.error_output.tag_configure("warning", foreground="orange")
        errors_exist = False

        errors_file = "./output/errors.txt"
        warnings_file = "./output/warnings.txt"

        if os.path.exists(errors_file):
            with open(errors_file, 'r') as file:
                error_content = file.read().strip()
                if error_content:
                    errors_exist = True
                    self._update_error_output("ERRORS:\n", "error")
                    self._update_error_output(error_content + "\n\n")
        if not errors_exist and os.path.exists(warnings_file):
            with open(warnings_file, 'r') as file:
                warning_content = file.read().strip()
                if warning_content:
                    self._update_error_output("WARNINGS:\n", "warning")
                    self._update_error_output(warning_content + "\n\n")
        if not errors_exist and (not os.path.exists(warnings_file) or not open(warnings_file).read().strip()):
            self._update_error_output("No errors found. Compilation successful!\n")
            self._update_status("Compilation successful")
        elif errors_exist:
            self._update_status("Compilation failed")
        else:
            self._update_status("Compilation successful")

if __name__ == "__main__":
    root = tk.Tk()
    app = CompilerGUI(root)
    root.mainloop()