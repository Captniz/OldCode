using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Termometro : MonoBehaviour
{

    GameObject Oven;
    public float smoothness = 2f;

    void Awake ()
    {
        Oven = GameObject.FindGameObjectWithTag ("Forno");
    }

    // Update is called once per frame
    void Update()
    {
        transform.localScale = Vector3.Lerp (transform.localScale, new Vector3(0.1f, Oven.GetComponent<OvenProprieties> ().Temperature / 100 , 0.1f),  smoothness);
    }
}
