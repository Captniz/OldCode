using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DegreeController : MonoBehaviour
{
    public float TempVariation = -10f;
    GameObject Oven;

    void Awake ()
    {
        Oven = GameObject.FindGameObjectWithTag ("Forno");
    }

    void OnCollisionEnter (Collision collisionInfo)
    {
        if (collisionInfo.collider.name == "Player")
        {
            if (TempVariation<0 && Oven.GetComponent<OvenProprieties> ().Temperature == 0)
            {
                
            }
            else
            {
                Oven.GetComponent<OvenProprieties> ().Temperature += TempVariation;     
            } 
        }
    }
}
