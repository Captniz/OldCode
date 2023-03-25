using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WoodProprieties : MonoBehaviour
{
    public bool IsBurned;
    public bool OnOven;
    public bool OnSaw;
    public Transform OvenCheck;
    public float SphereRadius = 0.4f;
    public LayerMask OvenMask;
    public LayerMask SawMask;
    public float BurningTemperature;
    GameObject Oven;
    MeshRenderer rend;
    [SerializeField] Color Burned;
    [SerializeField] [Range(0f, 1f)] float BurningSensibility;




    void Awake ()
    {
        Oven = GameObject.FindGameObjectWithTag ("Forno");
        rend = GetComponent<MeshRenderer>();
    }


    void Update()
    {
        OnOven = Physics.CheckSphere(OvenCheck.position,SphereRadius,OvenMask);
        OnSaw = Physics.CheckSphere(OvenCheck.position,SphereRadius,SawMask);

        if (OnOven==true && Oven.GetComponent<OvenProprieties> ().Temperature >= BurningTemperature)
        {
            IsBurned=true;
        }

        if (IsBurned) 
        {
            for (int i = 0; i < rend.materials.Length; i++)
            {
                rend.materials[i].color = Color.Lerp(rend.material.color,Burned,BurningSensibility);   
            }
        }
    }
}