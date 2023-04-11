namespace CUT4
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.button1 = new System.Windows.Forms.Button();
            this.frequencyRangeTextBox = new System.Windows.Forms.TextBox();
            this.lTextBox = new System.Windows.Forms.TextBox();
            this.firstAntennaHightLabel = new System.Windows.Forms.Label();
            this.lastAntennaHightLabel = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(12, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(1281, 844);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Segoe UI Semibold", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button1.Location = new System.Drawing.Point(1333, 12);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(150, 50);
            this.button1.TabIndex = 1;
            this.button1.Text = "Пуск";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // frequencyRangeTextBox
            // 
            this.frequencyRangeTextBox.Font = new System.Drawing.Font("Segoe UI Semibold", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.frequencyRangeTextBox.Location = new System.Drawing.Point(1333, 68);
            this.frequencyRangeTextBox.Name = "frequencyRangeTextBox";
            this.frequencyRangeTextBox.Size = new System.Drawing.Size(100, 31);
            this.frequencyRangeTextBox.TabIndex = 2;
            this.frequencyRangeTextBox.Text = "160";
            // 
            // lTextBox
            // 
            this.lTextBox.Font = new System.Drawing.Font("Segoe UI Semibold", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lTextBox.Location = new System.Drawing.Point(1333, 105);
            this.lTextBox.Name = "lTextBox";
            this.lTextBox.Size = new System.Drawing.Size(100, 31);
            this.lTextBox.TabIndex = 3;
            this.lTextBox.Text = "40";
            // 
            // firstAntennaHightLabel
            // 
            this.firstAntennaHightLabel.AutoSize = true;
            this.firstAntennaHightLabel.Font = new System.Drawing.Font("Segoe UI Semibold", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.firstAntennaHightLabel.Location = new System.Drawing.Point(1328, 149);
            this.firstAntennaHightLabel.Name = "firstAntennaHightLabel";
            this.firstAntennaHightLabel.Size = new System.Drawing.Size(0, 25);
            this.firstAntennaHightLabel.TabIndex = 4;
            // 
            // lastAntennaHightLabel
            // 
            this.lastAntennaHightLabel.AutoSize = true;
            this.lastAntennaHightLabel.Font = new System.Drawing.Font("Segoe UI Semibold", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lastAntennaHightLabel.Location = new System.Drawing.Point(1328, 185);
            this.lastAntennaHightLabel.Name = "lastAntennaHightLabel";
            this.lastAntennaHightLabel.Size = new System.Drawing.Size(0, 25);
            this.lastAntennaHightLabel.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Segoe UI Semibold", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(1439, 74);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(48, 25);
            this.label3.TabIndex = 6;
            this.label3.Text = "МГц";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Segoe UI Semibold", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(1439, 111);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(34, 25);
            this.label2.TabIndex = 7;
            this.label2.Text = "км";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1924, 1055);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.lastAntennaHightLabel);
            this.Controls.Add(this.firstAntennaHightLabel);
            this.Controls.Add(this.lTextBox);
            this.Controls.Add(this.frequencyRangeTextBox);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox frequencyRangeTextBox;
        private System.Windows.Forms.TextBox lTextBox;
        private System.Windows.Forms.Label firstAntennaHightLabel;
        private System.Windows.Forms.Label lastAntennaHightLabel;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
    }
}

