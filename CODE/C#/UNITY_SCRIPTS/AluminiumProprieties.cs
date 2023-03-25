using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AluminiumProprieties : MonoBehaviour
{
    public bool IsMelted;
    public bool OnOven;
    public bool OnAnvil;
    public bool Malleable;
    public Transform OvenCheck;
    public float SphereRadius = 0.4f;
    public LayerMask OvenMask;
    public LayerMask AnvilMask;
    public float MeltingTemperatureMin;
    public float MeltingTemperatureMax;
    GameObject Oven;
    MeshRenderer rend;
    [SerializeField] Color Melting;
    [SerializeField] Color MeltingEmission;
    [SerializeField] [Range(0f, 1f)] float MeltingSensibility;


    void Awake ()
    {
        //Ricerca variabili
        Oven = GameObject.FindGameObjectWithTag ("Forno");
        rend = GetComponent<MeshRenderer>();
    }
    void Update()
    {
        //Check della posizione
        OnOven = Physics.CheckSphere(OvenCheck.position,SphereRadius,OvenMask);
        OnAnvil = Physics.CheckSphere(OvenCheck.position,SphereRadius,AnvilMask);

        //Dectect della Fusione
        if (OnOven==true && Oven.GetComponent<OvenProprieties> ().Temperature >= MeltingTemperatureMin && Oven.GetComponent<OvenProprieties> ().Temperature <= MeltingTemperatureMax)
        {
            IsMelted=true;
        }

        //Effetti della Fusione
        if (IsMelted)
        {
            rend.material.color = Color.Lerp(rend.material.color,Melting,MeltingSensibility);
            rend.material.EnableKeyword("_EMISSION");
            rend.material.SetColor("_EmissionColor",MeltingEmission);
        }

        
        if (IsMelted && OnAnvil)
        {
            Malleable =  true;
        }

        if (IsMelted && !OnAnvil)
        {
            Malleable =  false;
        }
    }
}
