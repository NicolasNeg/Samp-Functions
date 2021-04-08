using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace S_F_autocomplete
{
    public partial class WinForm_01 : Form
    {
        public WinForm_01()
        {
            InitializeComponent();
        }
        public bool valid_func(string Function)
        {
            if (Function == null) return false;
            else if (Function == "CloseDialog(playerid)") return true;
            else if (Function == "SetPlayerMoney(playerid, money)") return true;
            else if (Function == "IsPlayerInAnyInterior(playerid)") return true;
            else if (Function == "SetPlayerHair(playerid, hair_type, slot)") return true;
            else if (Function == "OnVehicleDamage(driver, vehicleid, Float: health)") return true;
            else if (Function == "OnPlayerDGResponse(playerid, DG_ID, response, listitem)") return true;
            else if (Function == "CreateDialog(playerid, DIALOG_ID, DG_STYLE, DIALOG_CAPTION[], DIALOG_INFO[], DIALOG_BTN1[], DIALOG_BTN2[])") return true;
            else if (Function == "OnDGCreated(DG_ID)") return true;
            else return false;
        }
        private void Btn_insert_Click(object sender, EventArgs e)
        {
            if(valid_func(txtbox.Text) == false)
            {
                MessageBox.Show("invalid code", "Error.", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtbox.Clear();
            }
            else
            {
                MessageBox.Show("Function Selected: " + txtbox.Text + "", "Congrats.", MessageBoxButtons.OK, MessageBoxIcon.Information);
                txtbox.Clear();
            }
        }
        public void Q(string Function)
        {
            if(Function == "CloseDialog(playerid)")
            {
                MessageBox.Show("This function is for close the dialog of the playerid.", "How to use?", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if(Function == "SetPlayerMoney(playerid, money)")
            {
                MessageBox.Show("This function set the money of the playerid.", "How to use?", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if(Function == "IsPlayerInAnyInterior(playerid)")
            {
                MessageBox.Show("This function check if the playerid is in any interior.", "How to use?", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if(Function == "SetPlayerHair(playerid, hair_type, slot)")
            {
                MessageBox.Show("This function set the hair you select in hair_type for the playerid, the slot is only the indexobject.", "How to use?", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (Function == "OnVehicleDamage(driver, vehicleid, Float: health)")
            {
                MessageBox.Show("This callback is called when a vehicle is damaged.", "How to use?", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (Function == "OnPlayerDGResponse(playerid, DG_ID, response, listitem)")
            {
                MessageBox.Show("This callback is called when the playerid response to a dialogid.", "How to use?", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (Function == "CreateDialog(playerid, DIALOG_ID, DG_STYLE, DIALOG_CAPTION[], DIALOG_INFO[], DIALOG_BTN1[], DIALOG_BTN2[])")
            {
                MessageBox.Show("This function create a dialog.", "How to use?", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (Function == "OnDGCreated(DG_ID)")
            {
                MessageBox.Show("This callback is called when a dialog is created.", "How to use?", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Invalid code or bad words or code null", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btn_question_Click(object sender, EventArgs e)
        {
            Q(txtbox.Text);
            txtbox.Clear();
        }
    }
}
