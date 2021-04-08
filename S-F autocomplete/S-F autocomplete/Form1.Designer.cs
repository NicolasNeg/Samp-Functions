
namespace S_F_autocomplete
{
    partial class WinForm_01
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.txtbox = new System.Windows.Forms.TextBox();
            this.Title = new System.Windows.Forms.Label();
            this.Btn_insert = new System.Windows.Forms.Button();
            this.btn_question = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // txtbox
            // 
            this.txtbox.AutoCompleteCustomSource.AddRange(new string[] {
            "OnDGCreated(DG_ID)",
            "OnPlayerDGResponse(playerid, DG_ID, response, listitem)",
            "CreateDialog(playerid, DIALOG_ID, DG_STYLE, DIALOG_CAPTION[], DIALOG_INFO[], DIAL" +
                "OG_BTN1[], DIALOG_BTN2[])",
            "CloseDialog(playerid)",
            "SetPlayerMoney(playerid, money)",
            "IsPlayerInAnyInterior(playerid)",
            "OnVehicleDamage(driver,vehicleid, Float:health)",
            "SetPlayerHair(playerid, hair_type, slot)"});
            this.txtbox.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Suggest;
            this.txtbox.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.CustomSource;
            this.txtbox.Location = new System.Drawing.Point(177, 16);
            this.txtbox.Name = "txtbox";
            this.txtbox.Size = new System.Drawing.Size(191, 22);
            this.txtbox.TabIndex = 0;
            // 
            // Title
            // 
            this.Title.AutoSize = true;
            this.Title.Location = new System.Drawing.Point(12, 19);
            this.Title.Name = "Title";
            this.Title.Size = new System.Drawing.Size(159, 16);
            this.Title.TabIndex = 1;
            this.Title.Text = "Function/Callback here:";
            // 
            // Btn_insert
            // 
            this.Btn_insert.Location = new System.Drawing.Point(90, 90);
            this.Btn_insert.Name = "Btn_insert";
            this.Btn_insert.Size = new System.Drawing.Size(58, 36);
            this.Btn_insert.TabIndex = 2;
            this.Btn_insert.Text = "Insert";
            this.Btn_insert.UseVisualStyleBackColor = true;
            this.Btn_insert.Click += new System.EventHandler(this.Btn_insert_Click);
            // 
            // btn_question
            // 
            this.btn_question.Location = new System.Drawing.Point(12, 90);
            this.btn_question.Name = "btn_question";
            this.btn_question.Size = new System.Drawing.Size(59, 35);
            this.btn_question.TabIndex = 3;
            this.btn_question.Text = "?";
            this.btn_question.UseVisualStyleBackColor = true;
            this.btn_question.Click += new System.EventHandler(this.btn_question_Click);
            // 
            // WinForm_01
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(386, 138);
            this.Controls.Add(this.btn_question);
            this.Controls.Add(this.Btn_insert);
            this.Controls.Add(this.Title);
            this.Controls.Add(this.txtbox);
            this.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.SizableToolWindow;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MaximizeBox = false;
            this.Name = "WinForm_01";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Samp-Functions autocomplete [Beta]";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtbox;
        private System.Windows.Forms.Label Title;
        private System.Windows.Forms.Button Btn_insert;
        private System.Windows.Forms.Button btn_question;
    }
}

