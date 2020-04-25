using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void ProcId_Click(object sender, EventArgs e)
        {
            ProcIdLabel.Text = HardwareInfo.GetProcessorId();
        }

        private void ProcInfo_Click(object sender, EventArgs e)
        {
            ProcInfoLabel.Text = HardwareInfo.GetProcessorInformation();
        }

        private void BoardId_Click(object sender, EventArgs e)
        {
            BoardIdLabel.Text = HardwareInfo.GetBoardProductId();
        }

        private void Memory_Click(object sender, EventArgs e)
        {
            MemoryLabel.Text = HardwareInfo.GetPhysicalMemory();
        }

        private void RamSlots_Click(object sender, EventArgs e)
        {
            RamSlotsLable.Text = HardwareInfo.GetNoRamSlots();
        }

        private void CPUManuf_Click(object sender, EventArgs e)
        {
            CPUManufLabel.Text = HardwareInfo.GetCPUManufacturer();
        }

        private void CPUClSpeed_Click(object sender, EventArgs e)
        {
            CPUClSpeedLabel.Text = HardwareInfo.GetCPUCurrentClockSpeed().ToString();
        }

        private void CPUSpeed_Click(object sender, EventArgs e)
        {
            CPUSpeedLabel.Text = HardwareInfo.GetCpuSpeedInGHz().ToString();
        }

        private void PcName_Click(object sender, EventArgs e)
        {
            PcNameLabel.Text = HardwareInfo.GetComputerName();
        }

        private void MacAdress_Click(object sender, EventArgs e)
        {
            MacAdressLabel.Text = HardwareInfo.GetMACAddress();
        }

        private void BIOSCaption_Click(object sender, EventArgs e)
        {
            BIOSCaptionLabel.Text = HardwareInfo.GetBIOScaption();
        }

        private void BIOSMaker_Click(object sender, EventArgs e)
        {
            BIOSMakerLabel.Text = HardwareInfo.GetBIOSmaker();
        }
    }
}
